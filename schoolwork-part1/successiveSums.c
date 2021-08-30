#include <stdio.h>
#include "successiveSums.h"

int enterNaturalNumber() {
    int num;

    do {
        printf("Enter a natural number ( >= 0 ): ");
        scanf(" %d", &num);
    } while (num < 0);

    return num;
}

unsigned long long int productWithSuccessiveSums(int numA, int numB) {
    int i;
    unsigned long long int result = 0;

    if (numA == 0 || numB == 0) {
        return 0;
    }
    if (numA == 1) {
        return numB;
    }
    if (numB == 1) {
        return numA;
    }

    for(i = 0; i < numB; i++) {
        result += numA;
    }

    return result;
}
