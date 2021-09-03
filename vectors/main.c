#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#define TAM_INT sizeof(int)

int main() {
    /// Exercise 22 variables - Insert element into array with a given position
    int testVec[10] = {3, 5, -2, 10, 200, 1, 15, -8, 9, 10},
        cantElem = sizeof(testVec) / TAM_INT;
    int elem = 10000,
        pos = 10,
        result;

    /// Exercise 23 variables - Insert element into ascendingly ordered vector without altering the order.
    int testVec2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        cantElem2 = sizeof(testVec2) / TAM_INT;
    int elem2 = 5;

    /// Exercise 22
    printf("testVec[]: \n\n");
    printArray(testVec, cantElem, sizeof(testVec) / TAM_INT);

    result = insertElementInto(testVec, elem, pos, cantElem, cantElem);

    if ( result ) {
        printf("\n\ntestVec[] with changes: \n\n");
        printArray(testVec, cantElem, sizeof(testVec) / TAM_INT);
    } else {
        printf("\n\ntestVec[] didn't change.\n\n");
    }

    /// ############################################ ///

    /// Exercise 23
    printf("testVec2[]: \n\n");
    printArray(testVec2, cantElem2, cantElem2);

    insertElementIntoOrderedVector(testVec2, elem2, cantElem2);

    printf("\n\ntestVec2[] inserting %d: \n\n", elem2);
    printArray(testVec2, cantElem2, cantElem2);

    return 0;
}
