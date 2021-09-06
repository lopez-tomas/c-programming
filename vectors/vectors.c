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

int insertElementInto(int* vec, int element, int pos, int* posAct, int tam) {
    int insertingPos = *posAct,
        posElementAct = *posAct;
    int *vAux = vec;

    if (pos > tam) {
        return 0;
    }

    vec += insertingPos;
    vAux += insertingPos - 1;

    if (pos == *posAct) {
        if (*posAct == tam) {
            *vAux = element;
        } else {
            *vec = element;
            (*posAct)++;
        }
        return 1;
    }

    if (pos < *posAct && *posAct == tam) {
        vec--;
        vAux--;
        posElementAct--;
    }

    while(pos < posElementAct) {
        *vec = *vAux;

        vec--;
        vAux--;
        posElementAct--;
    }

    *vec = *vAux;
    *vAux = element;
    if (*posAct < tam) {
        (*posAct)++;
    }

    return 3;
}

void insertElementIntoOrderedVector(int* vec, int element, int* posAct, int tam) {
    int *vAux = vec;

    vec += (*posAct);
    vAux += (*posAct) - 1;

    if (*posAct == tam) {
        vec--;
        vAux--;
    }

    while (element < *vAux) {
        *vec = *vAux;

        vec--;
        vAux--;
    }

    *vec = element;

    if (*posAct < tam) {
        (*posAct)++;
    }
}
