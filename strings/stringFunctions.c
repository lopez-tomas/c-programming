#include <stdio.h>
//#include <stdlib.h
#include <stddef.h>
#include "stringFunctions.h"
#include "../schoolwork-part1/macros.h"

char* str_cpy(char* destiny, char* origin) {
    char *stringMod = destiny;
    while (*origin) { // while(*origin != '\0') { ... }
        *destiny = *origin;

        origin++;
        destiny++;
    }
    *destiny = '\0';

    return stringMod;
}

unsigned int str_len(char* origin) {
    unsigned int cantChars = 0;

    while(*origin) {
        cantChars++;
        origin++;
    }

    return cantChars;
}

char* str_cat(char* destiny, char* origin) {
    char *stringAux = destiny;

    while (*destiny) {
        destiny++;
    }

    while (*origin) {
        *destiny = *origin;

        destiny++;
        origin++;
    }

    *destiny = '\0';

    return stringAux;
}

char* str_chr(char* source, char character) {
    while (*source && *source != (char)character) {
        source++;
    }
    return *source == (char)character ? source : NULL;
}

char* str_rchr(char* source, char character) {
    char *aux = source;

    while (*aux) {
        aux++;
    }
    while (aux > source && *aux != (char)character) {
        aux--;
    }

    return *aux == character ? aux : NULL;
}

char* str_lwr(char* source) {
    char *aux = source;

    while (*source) {
        *source = TO_MINUS(*source);
        source++;
    }

    return aux;
}

char* str_upr(char* source) {
    char *aux = source;

    while (*source) {
        *source = TO_MAYUS(*source);
        source++;
    }

    return aux;
}

int str_cmp(char* source1, char* source2) {
    if (!(*source1) && !(*source2)) {
        return 0;
    }

    while (*source1 && *source1 == *source2) {
        source1++;
        source2++;
    }

//    return *source1 ?
//                    ( *source2 ? ( *source1 == *source2 ? 0 : *source1 > *source2 ? 1 : -1 ) : 1 )
//                    :
//                    ( *source2 ? -1 : 0 );
    return *(unsigned char *)source1 - *(unsigned char *)source2;
//    return *source1 - *source2;
}

int str_cmpi(char* source1, char* source2) {
    while ( *source1 && TO_MINUS(*source1) == TO_MINUS(*source2) ) {
        source1++;
        source2++;
    }

    return TO_MINUS(*(unsigned char *)(source1)) - TO_MINUS(*(unsigned char *)(source2));
}

int isPalindrome(char* source) {
    unsigned int chars = str_len(source) + 1;
    char auxString[chars]; // I don't declare a char* because I need a real copy of my original string to work.
    char* iniString;
    char* endString;
    int answer = 0;

    if (chars <= 1) {
        return answer;
    }

    str_cpy(auxString, source); // I need a copy of my original string to not modify it.
    noWhiteSpaces(auxString, &chars);

    chars = str_len(auxString); // re-calculate length of auxString.

    iniString = auxString;
    endString = auxString + chars - 1;

    while (iniString < endString) {
        if (TO_MINUS(*iniString) != TO_MINUS(*endString)) {
            return answer;
        }
        iniString++;
        endString--;
    }

    return answer = 1;
}
