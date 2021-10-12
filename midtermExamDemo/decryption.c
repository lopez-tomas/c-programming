#include "decryption.h"
#include "stringFunctions.h"
#include "macros.h"

char* nextWord(char* source, unsigned* wordLength) {
    unsigned letters = 0;
    char* wordStart;

    while(*source && !IS_LETTER(*source)) {
        source++;
    }
    wordStart = source;

    while(*source && IS_LETTER(*source)) {
        letters++;
        source++;
    }
    *wordLength = letters;

    return wordStart;
}

void displaceWord(char* wordStart, char* wordEnd, const char* group, int displacement) {
    unsigned group_size = str_len((char*)group);
    char* group_start = (char*)group;
    char* group_aux = group_start;
    char* letter;

    while(wordStart <= wordEnd) {
        if(isLetterInGroup(*wordStart, group)) {
            letter = str_chr((char*)group, *wordStart);

            group_aux += ABS(letter - group_start + displacement) % group_size;
            *wordStart = *group_aux;
            group_aux = group_start;
        }

        wordStart++;
    }
}

int isLetterInGroup(char letter, const char* group) {
    return (str_chr((char*)group, letter)) ? 1 : 0;
}

void invertWord(char* wordStart, char* wordEnd) {
    while(wordStart < wordEnd) {
        swapCharacters(wordStart, wordEnd);

        wordStart++;
        wordEnd--;
    }
}

void swapCharacters(char* letter1, char* letter2) {
    char aux = *letter1;
    *letter1 = *letter2;
    *letter2 = aux;
}

char* decryptionWithDisplacement(char* source, const char* group, int displacement, unsigned isInverted) {
    char* wordStart;
    char* wordEnd = source;
    unsigned wordLength;

    while(*wordEnd) {
        wordStart = nextWord(wordEnd, &wordLength);
        wordEnd = wordStart + wordLength - 1;

        displaceWord(wordStart, wordEnd, group, displacement);

        if(isInverted) {
            invertWord(wordStart, wordEnd);
        }

        wordEnd++;
    }

    return source;
}
