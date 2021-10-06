#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

char* special_strcpy(char* dest, const char* orig) {
    int numChars = strlen(orig) + 1;

    dest = calloc(numChars, sizeof(char));

    return (dest == NULL ? NULL : strcpy(dest, orig));
}

/*void* mem_move(void* s1, const void* s2, size_t numberBytes) {*/
    /*void* initialPos = s1;*/
    /*void* aux;*/
    /*int numChars = strlen(s2) + 1;*/
    /*int i;*/

    /*aux = calloc(numChars, sizeof(char));*/
    /*if(aux == NULL) {*/
        /*free(aux);*/
        /*return NULL;*/
    /*}*/
    /*strcpy(aux, s2);*/

    /*[>s1 = calloc(numChars, sizeof(char));<]*/
    /*[>if(s1 == NULL) {<]*/
        /*[>free(aux);<]*/
        /*[>free(s1);<]*/
        /*[>return NULL;<]*/
    /*[>}<]*/

    /*for(i = 0; i < numberBytes; i++) {*/
        /**(char*)s1 = *(char*)aux;*/

        /*aux++;*/
        /*s1++;*/
    /*}*/
    /*[>free(aux);<]*/

    /*return initialPos;*/
/*}*/

int** createIntegerMatrix(unsigned numberFiles, unsigned numberColumns) {
    int** matrix;
    int** initialPos;
    int sizeElement = sizeof(int);
    int i, j;

    matrix = (int**)malloc(numberFiles * sizeof(int*));
    if(matrix == NULL) {
        puts("Memory for matrix could not be assignated.");
        return NULL;
    }
    initialPos = matrix;

    for(i=0; i < numberFiles; i++, matrix++) {
        *matrix = (int*)malloc(numberColumns * sizeElement);
        if(matrix == NULL) {
            puts("Memory for *matrix could not be assignated.");

            for(j = 0; j < i; j++, matrix--) {
                free(*matrix);
            }

            free(matrix);
            return NULL;
        }
    }

    return initialPos;
}
