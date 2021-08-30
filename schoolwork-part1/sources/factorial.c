#ifdef _WIN32
#define CLEAR "cls"
#else // In any other OS
#define CLEAR "clear"
#endif

#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

#define MAX_FACT 21

unsigned long long int factorialOf(unsigned int x) {
    unsigned long long int factorial = x; // user's number assigned as initial value of its factorial.

    if (x <= 1) {
        factorial = 1;
    } else {
        for(int i = 1; i < x; i++) {
            factorial *= (x - i);
        }
    }
    return factorial;
}

unsigned int enterNumberToFactor() {
    unsigned int num;
    int aux = 0;

    do {
        if (aux == 1) {
            system(CLEAR);
        }
        printf("Enter a number to factor [0 - %d]: ", MAX_FACT);
        scanf(" %u", &num);
        aux = 1;
    } while(num < 0 || num > MAX_FACT);

    return num;
}

void printFactoredNumber(unsigned int baseNumber, unsigned long long int factoredNumber) {
    printf("The factorial of %u is %llu", baseNumber, factoredNumber);
}
