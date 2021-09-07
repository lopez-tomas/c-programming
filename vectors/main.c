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

    /// Variables to test str_chr & str_chr
//    char src[] = "Hello, how are you?";
//    int chr = (int)('x');
//    char chr2 = 'x';

    /// Variables to test str_lwr & str_upr
//    char mayus[] = "this string has full minus chars.";
//    char minus[] = "THIS STRING HAS FULL MAYUS CHARS.";

    /// Variables to test str_cmp & str_cmpi
    char src1[] = "abcd";
    char src2[] = "abcd";
    int result;

//    printf("dest: %s -> %d\n", dest, destChars);
//    printf("orig: %s -> %d\n", orig, origChars);
//
//    str_cat(dest, orig);
//    printf("%s (%d)", dest, str_len(dest));

//    for(int i = 0; i < str_len(src) + 1; i++) {
//        printf("%c -> %p\n", src[i], &src[i]);
//    }
//    printf("\n%s -> %c found at %p\n\n", src, (char)chr, str_chr(src, chr));
//
//    for(int i = 0; i < str_len(src) + 1; i++) {
//        printf("%c -> %p\n", src[i], &src[i]);
//    }
//    printf("\n%s -> %c found at %p\n\n", src, chr, str_rchr(src, chr2));

//    printf("(original) -> %s\n", minus);
//    printf("(changed)  -> %s\n\n", str_lwr(minus));
//    printf("(original) -> %s\n", mayus);
//    printf("(changed)  -> %s\n\n", str_upr(mayus));

    result = str_cmp(src1, src2);
    if (result == 0) {
        printf("%s == %s\n", src1, src2);
    } else if (result > 0) {
        printf("%s > %s\n", src1, src2);
    } else {
        printf("%s < %s\n", src1, src2);
    }

    return 0;
}
