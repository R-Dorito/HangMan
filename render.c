#include "render.h"
#include <stdio.h>
#include <stdlib.h>

void drawHangman(int wrong) {
    if(wrong > 8) {wrong = 8;}
    const char *stages[] = {
        // 0 wrong
        "       \n"
        "       \n"
        "       \n"
        "       \n"
        "       \n"
        "       \n"
        "=========\n",
        // 1 wrong
        "      +\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        // 2 wrong
        "  +---+\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        // 3 wrong
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        // 4 wrong
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        // 5 wrong
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        // 6 wrong
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        // 7 wrong
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "=========\n",
        // 8 wrong (FULL HANGMAN)
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "=========\n"
    };

    printf("%s", stages[wrong]);
}
