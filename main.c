#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#include "render.c"


bool charInArray(char *arr, char c) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == c) return true;
    }
    return false;
}

bool buildGameResult(char *result, const char *word, const char *guesses) {
    bool complete = true;  // assume win unless '_' appears

    for (int i = 0; word[i] != '\0'; i++) {
        if (charInArray((char*)guesses, word[i])) {
            result[i] = word[i];     
        } else {
            result[i] = '_';         
            complete = false;
        }
    }

    result[strlen(word)] = '\0';   
    return complete;  
}

char* readFile(){
    char **words = NULL;        
    int size = 0;               
    char buffer[100];           
    FILE *fp = fopen("wordsList.txt", "r");
    int returnNumber;
    int min = 0, max = 0;

    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
    }

    srand(time(NULL));
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // remove newline at end if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // allocate memory for the new word
        char *word = malloc(strlen(buffer) + 1);
        strcpy(word, buffer);

        // resize the words array
        words = realloc(words, (size + 1) * sizeof(char*));
        words[size] = word;
        size++;
    }
    max = size -1;
    returnNumber = rand() % max;
    //printf("DEBUGGER Return number: %d, Max: %d\n", returnNumber, size);
    fclose(fp);
    return words[returnNumber];
}

char* toLowerCase(char *arr){
    for (int i = 0; arr[i] != '\0'; i++) {
        arr[i] = tolower(arr[i]);
    }
    //printf("%s", arr);
    return arr;
}

int main() {
    char *word = toLowerCase(readFile());      
    char guesses[50] = "";       
    char gameResult[50] = "";    
    char guess;
    void drawHangman(int wrong);

    int turns = 0, wrongNum = 0;
    bool win = false, valid = true;
    bool isGuessed = false;

    do {
        printf("Word Guessing Game\n\n");
        printf("debug: word is: %s \n", word);
        printf("Turn number: %d\t", turns);
        printf("Number of Wrongs: %d\n", wrongNum);

        drawHangman(wrongNum);
        win = buildGameResult(gameResult, word, guesses);

        if(win){break;}

        printf("%s\n", gameResult);
        printf("Guess a letter: ");

        if(isGuessed){
            printf("\n%c has been guessed\n", guess);
            isGuessed = false;
        }
        if(!valid){
            printf("\nplease enter a letter\n");
            valid = true;
        }

        scanf(" %c", &guess);
        while (getchar() != '\n');// remove extra input if user types more than one char
        //guess = tolower(guess);
        isGuessed = charInArray(guesses,guess);

        if(!charInArray(word,guess) && isalpha(guess)){
            wrongNum++;
        }
        if(!isalpha(guess)){
            valid = false;
        }

        if(!isGuessed){
            guesses[turns++] = guess;
            guesses[turns] = '\0';
        }

        // Clear screen
        system("clear");

    } while (!win && wrongNum < 8);

    if(wrongNum == 8 && !win){
        printf("you loose\n");
        drawHangman(wrongNum);
    }
    else{
        printf("You win!\n");
    }
    printf("The word was: %s\n", word);

    return 0;
}
