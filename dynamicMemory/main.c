#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main() {
    char palabra[1000] = "Hola mundo.";
    char* pC;

    pC = special_strcpy(pC, palabra);
    if (pC == NULL) {
        printf("The memory could not be obtained.\n");
    } else {
        printf("String: \"%s\" | Characters: %d (+ \'\\0\')\n", pC, (int)strlen(pC) + 1);
    }
    free(pC);


    // TO DO
    // intA(int a, int b) {
    // char x[1024][1024*2];
    //
    // createIntegerMatriz( ???, numberFiles, numberColumns) {
    //
    // }

    return 0;
}
