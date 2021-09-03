#include <stdio.h>
#include "vectors.h"

void printArray(int* vec, int posAct, int tam) {
    int i;
//    printf("%p\n\n", &vec);
    for(i = 0; i < posAct; i++) {
        printf("[%d] pos %d -> %d\n", i, i+1, *vec);
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

int insertElementInto(int* vec, int element, int pos, int posAct, int tam) {
    int realPos,
        insertingPos = posAct - 1; // posAct has the position of the next value of my vector, but I don't
    int *vAux = vec;               // want it, I need the LAST ELEMENT of vector so I decrement it by one.

    vec += insertingPos;
    vAux += insertingPos - 1;

    if ( pos > tam ) {
        return 0;
    }

    realPos = pos - 1;

    if ( insertingPos == realPos ) { // User's desired position is equal to the position of the last
        *vec = element;              // element of vector, so I don't have to move other positions.
        return 1;
    }

    while (insertingPos > realPos) {
        *vec = *vAux;

        insertingPos--;
        vec--;
        vAux--;
    }

    *vec = element;

    return 1;
}
