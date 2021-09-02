#include <stdio.h>
#include "vectors.h"

void printArray(int* vec, int posAct, int tam) {
    int i;
//    printf("%p\n\n", &vec);
    for(i = 0; i < posAct; i++) {
        printf("pos %d -> %d\n", i, *vec);
        vec++;
    }
}

int fillArray(int* vec, int posAct, int tam) {
    int condition;

    if (posAct == tam) {
        return posAct;
    }

    vec += posAct;

    printf("\nDo you want to fill the array (1: Yes/ 0: No): ");
    scanf(" %d", &condition);
    while (condition && posAct < tam) {
        printf("\nEnter a number (-1 to exit): ");
        scanf(" %d", vec);

        vec++;
        posAct++;

        printf("\n\nDo you want to fill the array (1: Yes/ 0: No): ");
        scanf(" %d", &condition);
    }
    return posAct;
}
