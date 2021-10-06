#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main() {
    char palabra[1000] = "Hola mundo.";
    char* pC = "";

    pC = special_strcpy(pC, palabra);
    if (pC == NULL) {
        printf("The memory could not be obtained.\n");
    } else {
        printf("String: \"%s\" | Characters: %d (+ \'\\0\')\n", pC, (int)strlen(pC) + 1);
    }
    free(pC);

//    printf("Original word: %s\n", palabra);
//    for(int i = 0; i < strlen(palabra); i++) {
//        printf("palabra[%.2d] = %c ; %p\n", i, palabra[i], &palabra[i]);
//    }
//
//    if (mem_move(palabra + 2, palabra, 4 * sizeof(char)) == NULL ) {
//        printf("No se pudo reservar memoria.");
//    } else {
//        printf("\n\nWord changed: %s\n", palabra);
//        for(int i = 0; i < strlen(palabra); i++) {
//            printf("palabra[%.2d] = %c ; %p\n", i, palabra[i], &palabra[i]);
//        }
//    }

    // createIntegerMatriz( ???, numberFiles, numberColumns) {

    /*int** biggerMatrix = createIntegerMatrix(1600, 1600);*/
    /*fillIntegerMatrix(biggerMatrix, 1600, 1600);*/
    /*showIntegerMatrix(biggerMatrix, 1600, 1600);*/

    unsigned numberFiles = 10,
             numberColumns = 5;
    int** matrix = createIntegerMatrix(numberFiles, numberColumns);

    printf("\n\nintegerMatrix[%d][%d]:\n", numberFiles, numberColumns);
    fillIntegerMatrix(matrix, numberFiles, numberColumns);
    showIntegerMatrix(matrix, numberFiles, numberColumns);


    return 0;
}
