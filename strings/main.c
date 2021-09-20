#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#define SIZE 100

int main() {
    /// Variables to test str_len & str_cat
    char orig[] = "world";
    char dest[SIZE] = "hello";
    unsigned int destChars,
                 origChars;

    /// Variables to test str_chr & str_rchr
    char src[] = "Hello, how are you?";
    char chr = 'x';

    /// Variables to test str_lwr & str_upr
    char mayus[] = "this string has full minus chars.";
    char minus[] = "THIS STRING HAS FULL MAYUS CHARS.";

    /// Variables to test str_cmp & str_cmpi
    char src1[] = "hello123";
    char src2[] = "hEllo123";
    int result;

    /// Variables to test isPalindrome
    char palindrome[] = "A luna ese anula";
    char palindrome2[] = "Amor a Roma";
    int answerPalindrome;

    /// Variables to test numericValueOf
    char stringToNumber[] = "-1-\t23";
    long long int value;

    /// ############################################ ///

    /// Test for str_len() & str_cat()
    destChars = str_len(dest);
    origChars = str_len(orig);

    printf("dest: %s -> %d\n", dest, destChars);
    printf("orig: %s -> %d\n", orig, origChars);

    str_cat(dest, orig);
    printf("%s (%d)", dest, str_len(dest));

    /// Test for str_chr() & str_rchr()
    for(int i = 0; i < str_len(src) + 1; i++) {
        printf("%c -> %p\n", src[i], &src[i]);
    }
    printf("\n%s -> %c found at %p\n\n", src, chr, str_chr(src, chr));

    for(int i = 0; i < str_len(src) + 1; i++) {
        printf("%c -> %p\n", src[i], &src[i]);
    }
    printf("\n%s -> %c found at %p\n\n", src, chr, str_rchr(src, chr));

    /// Test for str_lwr() & str_upr()
    printf("(original) -> %s\n", minus);
    printf("(changed)  -> %s\n\n", str_lwr(minus));
    printf("(original) -> %s\n", mayus);
    printf("(changed)  -> %s\n\n", str_upr(mayus));

    /// Test for str_cmp()
    result = str_cmp(src1, src2);
    if (result == 0) {
        printf("%s == %s\n", src1, src2);
    } else if (result > 0) {
        printf("%s > %s\n", src1, src2);
    } else {
        printf("%s < %s\n", src1, src2);
    }

    /// Test for str_cmpi()
    result = str_cmpi(src1, src2);
    if (result == 0) {
        printf("%s == %s\n\n", src1, src2);
    } else if (result > 0) {
        printf("%s > %s\n\n", src1, src2);
    } else {
        printf("%s < %s\n\n", src1, src2);
    }

    /// Test for isPalindrome()
    answerPalindrome = isPalindrome(palindrome);
    if (answerPalindrome) {
        printf("\n\"%s\" is a palindrome.\n\n", palindrome);
    } else {
        printf("\n\"%s\" is not a palindrome.\n\n", palindrome);
    }

    /// Test for numericValueOf()
    value = numericValueOf(stringToNumber);
    printf("\"%s\" = %lld\n", stringToNumber, value);

    return 0;
}
