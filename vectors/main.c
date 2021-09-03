#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#define TAM_INT sizeof(int)

int main() {
    /// Exercise 22 variables - Insert element into array with a given position
    int testVec[10] = {3, 5, -2, 10, 200, 1, 15, -8, 9, 10},
        cantElem = sizeof(testVec) / TAM_INT;
    int elem = 10000,
        pos = 6,
        result;

    printf("testVec[]: \n\n");
    printArray(testVec, cantElem, sizeof(testVec) / TAM_INT);

    result = insertElementInto(testVec, elem, pos, cantElem, cantElem);

    printf("\n\ntestVec[] with changes (or not): \n\n");
    printArray(testVec, cantElem, sizeof(testVec) / TAM_INT);

    return 0;
}
