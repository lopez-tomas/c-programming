#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#define TAM_INT sizeof(int)
#define TAM_VEC 10
#define SIZE 100

int main() {
    /// Exercise 22 variables - Insert element into array with a given position
//    int testVec[TAM_VEC] = {10, 20, 30, 40},
//        numberElements = 4;
//    int elem = 50,
//        pos = numberElements;
//
//    /// Exercise 23 variables - Insert element into ascendingly ordered vector without altering the order.
//    int testVec2[10] = {10, 20, 30, 40},
//        numberElements2 = 4;
//    int elem2;

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
    /// Strings

    /// Variables to test str_len & str_cat
//    char orig[] = "world";
//    char dest[SIZE] = "hello";
//    unsigned int destChars = str_len(dest),
//                 origChars = str_len(orig);

    /// Variables to test str_chr
    char src[] = "Hello, how are you?";
    int chr = (int)('x');

//    printf("dest: %s -> %d\n", dest, destChars);
//    printf("orig: %s -> %d\n", orig, origChars);
//
//    str_cat(dest, orig);
//    printf("%s (%d)", dest, str_len(dest));

    for(int i = 0; i < str_len(src) + 1; i++) {
        printf("%c -> %p\n", src[i], &src[i]);
    }
    printf("\n\n%s -> %c found at %p", src, (char)chr, str_chr(src, chr));

    return 0;
}
