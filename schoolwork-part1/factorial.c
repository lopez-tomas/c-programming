#ifdef _WIN32
#define CLEAR "cls"
#else // In any other OS
#define CLEAR "clear"
#endif

#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

double factorialOf(int x) {
    double factorial = x; // user's number assigned as initial value of its factorial.

    if (x <= 1) {
        factorial = 1;
    } else {
        for(int i = 1; i < x; i++) {
            factorial *= (x - i);
        }
    }
    return factorial;
}

int enterNumberToFactor(int maxNumberToFactor) {
    int num;
    int aux = 0;

    do {
        if (aux == 1) {
            system(CLEAR);
        }
        printf("Enter a number to factor [0 - %d]: ", maxNumberToFactor);
        scanf(" %d", &num);
        aux = 1;
    } while(num < 0 || num > maxNumberToFactor);

    return num;
}

void printFactoredNumber(int baseNumber, double factoredNumber, int maxFactoredNumber) {
    if(baseNumber <= maxFactoredNumber) {
        printf("The factorial of %d is %.2lf", baseNumber, factoredNumber);
    } else {
        printf("The factorial of %d is %le", baseNumber, factoredNumber);
    }
}
