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

void eliminateElementOnce(int* vec, int element, int* posAct, int tam) {
    int* vAux = vec + 1;
    int numElem = 1,
        flag = 0;

    while (*vec != element) {
        vec++;
        vAux++;
        numElem++;
    }

    if (numElem == *posAct && *vec == element) {
        (*posAct)--;
        return;
    }

    while (numElem < *posAct) {
        *vec = *vAux;

        vec++;
        vAux++;
        numElem++;
        flag = 1;
    }
    if (flag) {
        (*posAct)--;
    }
}

void eliminateElement(int* vec, int element, int* posAct, int tam) {
    int* nextPos = vec + 1;
    int* currentPos = vec;
//    int* pos;
    int position = 0, i;
    int cantElem;

    while (position < *posAct) {
        cantElem = (*posAct) - 1;

        if (*currentPos == element) {
            for (i = position; i < cantElem; i++) {
                    *vec = *(nextPos);
                    vec++;
                    nextPos++;
            }
            (*posAct)--;
            currentPos--;
            vec = currentPos;
            nextPos = vec + 1;
            position--;
        }
        position++;
        currentPos++;
        vec = currentPos;
        nextPos = vec + 1;
    }
}

int disjointVectors(int* vec1, const int numberElementsVec1, int* vec2, const int numberElementsVec2) {
    int *auxGreater,
        *auxSmaller,
        *auxAux;
    int disjoint = 1,
        i, j,
        greater,
        smaller;

    if (numberElementsVec1 == 0 && numberElementsVec2 == 0) {
        return disjoint;
    }

    if (numberElementsVec1 < numberElementsVec2) {
        greater = numberElementsVec2;
        smaller = numberElementsVec1;

        auxGreater = vec2;
        auxAux = auxGreater;
        auxSmaller = vec1;
    } else {
        greater = numberElementsVec1;
        smaller = numberElementsVec2;

        auxGreater = vec1;
        auxAux = auxGreater;
        auxSmaller = vec2;
    }

    for(i = 0; i < smaller; i++) {
        auxGreater = auxAux;

        for(j = 0; j < greater; j++) {
            if (*auxSmaller == *auxGreater) {
                return disjoint = 0;
            }

            auxGreater++;
        }

        auxSmaller++;
    }

    return disjoint;
}

int symmetricVector(int* vec, const int numElements) {
    int *vecEnd = vec + numElements - 1;
    int symmetric = 1;

    /// version 1
    while ( vec < vecEnd ) {
        if (*vec != *vecEnd) {
            return symmetric = 0;
        }
        vec++;
        vecEnd--;
    }
    return symmetric;

    /// version 2
//    while ( vec < vecEnd && *vec == *vecEnd ) {
//        vec++;
//        vecEnd--;
//    }
//    if ( vec < vecEnd ) {
//        return symmetric = 0;
//    }
//    return symmetric;
}
