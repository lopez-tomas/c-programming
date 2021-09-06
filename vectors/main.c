#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#define TAM_INT sizeof(int)
#define TAM_VEC 10

int main() {
    /// Exercise 22 variables - Insert element into array with a given position
    int testVec[TAM_VEC] = {10, 20, 30, 40},
        numberElements = 4;
    int elem = 50,
        pos = numberElements;

    /// Exercise 23 variables - Insert element into ascendingly ordered vector without altering the order.
    int testVec2[10] = {10, 20, 30, 40},
        numberElements2 = 4;
    int elem2;

    /// Exercise 22
    printf("testVec[]: \n\n");
    printf("Cant. elements: %d\n\n", numberElements);
    printArray(testVec, numberElements, TAM_VEC);

    insertElementInto(testVec, elem, pos, &numberElements, TAM_VEC);

    printf("\n\n");
    printf("Cant. elements: %d\n\n", numberElements);
    printArray(testVec, numberElements + 1, TAM_VEC + 1);

    /// ############################################ ///

    /// Exercise 23
    printf("testVec2[]: \n\n");
    printArray(testVec2, numberElements2 + 1, TAM_VEC + 1);

    elem2 = 5;
    insertElementIntoOrderedVector(testVec2, elem2, &numberElements2, TAM_VEC);

    printf("\n\ntestVec2[] inserting %d: \n\n", elem2);
    printArray(testVec2, numberElements2 + 1, TAM_VEC + 1);

    /// ############################################ ///
    /// Strings

    return 0;
}
