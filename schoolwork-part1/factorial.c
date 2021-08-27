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

    do {
        printf("Enter a number to factor [0 - %d]: ", maxNumberToFactor);
        scanf(" %d", &num);
    } while(num < 0 || num > maxNumberToFactor);

    return num;
}

void printFactoredNumber(int baseNumber, double factoredNumber, int maxFactoredNumber) {
    if(baseNumber <= maxFactoredNumber) {
        printf("%d factor is %.2lf", baseNumber, factoredNumber);
    } else {
        printf("%d factor is %le", baseNumber, factoredNumber);
    }
}
