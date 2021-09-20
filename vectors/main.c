#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#define TAM_INT_VEC(vec) (sizeof(vec))
#define TAM_INT sizeof(int)
#define CANT_ELEM_INT_VEC(vec) ( TAM_INT_VEC(vec) / TAM_INT )
#define TAM_VEC 10

int main() {
    /// Exercise 22 variables - Insert element into array with a given position
//    int testVec[TAM_VEC] = {10, 20, 30, 40},
//        numberElements = 4;
//    int elem = 50,
//        pos = numberElements;
//
    /// Exercise 23 variables - Insert element into ascendingly ordered vector without altering the order.
//    int testVec2[10] = {10, 20, 30, 40},
//        numberElements2 = 4;
//    int elem2;

    /// Exercise 25 variables - Eliminate the first occurrence of a given element within a vector.
//    int testVec25[] = { 3, 5, 7, 9, 11, 13, 15 },
//        numberElements = 7,
//        elementA = 9,
//        elementB = 15;

    /// Exercise 26 variables - Eliminate all occurrences of a given element within a vector.
    int testVec26[] = { 3, 5, 100, 1 },
        numberElements26 = CANT_ELEM_INT_VEC(testVec26),
        element26 = 9;

    /// Exercise Disjoint variables - Determine if two given vectors (int) are disjoints/incompatibles or not
//    int vec1[] = { 10, 20, 30, 40, 50 },
//        numElem1 = 5;
//    int vec2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 10 },
//        numElem2 = 10;
//    int disjoint;

    /// Exercise Symmetric variables - Determine if a vector is symmetric
//    int vecSymmetric[] = { 1, 2, 3, 3, 2, 1 },
//        cE = 6;

    /// ############################################ ///

    /// Exercise 22
//    printf("testVec[]: \n\n");
//    printf("Cant. elements: %d\n\n", numberElements);
//    printArray(testVec, numberElements, TAM_VEC);
//
//    insertElementInto(testVec, elem, pos, &numberElements, TAM_VEC);
//
//    printf("\n\n");
//    printf("Cant. elements: %d\n\n", numberElements);
//    printArray(testVec, numberElements + 1, TAM_VEC + 1);

    /// ############################################ ///

    /// Exercise 23
//    printf("testVec2[]: \n\n");
//    printArray(testVec2, numberElements2 + 1, TAM_VEC + 1);
//
//    elem2 = 5;
//    insertElementIntoOrderedVector(testVec2, elem2, &numberElements2, TAM_VEC);
//
//    printf("\n\ntestVec2[] inserting %d: \n\n", elem2);
//    printArray(testVec2, numberElements2 + 1, TAM_VEC + 1);

    /// ############################################ ///

    /// Exercise 25
//    printf("testVec25[] - Number of elements: %d \n\n", numberElements);
//    printArray(testVec25, numberElements + 1, TAM_VEC);
//
//    eliminateElementOnce(testVec25, elementA, &numberElements, TAM_VEC);
//
//    printf("\n\ntestVec25[] eliminating %d - Number of elements: %d \n\n", elementA, numberElements);
//    printArray(testVec25, numberElements + 1, TAM_VEC);

    /// ############################################ ///

    /// Exercise 26
    printf("testVec26[] - Number of elements: %d \n\n", numberElements26);
    printArray(testVec26, numberElements26 + 1, TAM_INT_VEC(testVec26));

    eliminateElementOnce(testVec26, element26, &numberElements26, TAM_VEC);

    printf("\n\ntestVec26[] eliminating %d - Number of elements: %d \n\n", 9, numberElements26);
    printArray(testVec26, numberElements26 + 1, TAM_INT_VEC(testVec26) + 1);

    /// ############################################ ///

    /// Exercise - Disjoint/Incompatible vectors
//    disjoint = disjointVectors(vec1, numElem1, vec2, numElem2);
//    if (disjoint) {
//        printf("vec1 & vec2 are disjoint/incompatible vectors.");
//    } else {
//        printf("vec1 & vec2 are compatible vectors.");
//    }

    /// ############################################ ///

    /// Exercise - Symmetric vector
//    if (symmetricVector(vecSymmetric, cE)) {
//        printf("vecSymmetric[] is symmetric.");
//    } else {
//        printf("vecSymmetric[] is not symmetric.");
//    }

    return 0;
}
