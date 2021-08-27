#include <stdio.h>
#include "naturalExponential.h"
#include "factorial.h"

#define MAX_FLOAT 1
#define MIN_FLOAT 0.000001

double calculateNaturalExponential(int x, float tol) {
    double e = 0,
           term,
           factoredExponent;
    int numRaised;
    int exponent = 0;

    do {
        numRaised = raiseNumber(x, exponent);
        factoredExponent = factorialOf(exponent);
        term = numRaised / factoredExponent;

        e += term;
    } while(term > tol);

    return e;
}

int enterNumber() {
    int num;

    printf("Enter your number to calculate e^x: ");
    scanf(" %d", &num);

    return num;
}

float enterTol() {
    float tol;

    do {
        printf("Enter the desired tolerance [%d - %f]: ", MAX_FLOAT, MIN_FLOAT);
        scanf(" %f", &tol);
    } while( tol > MAX_FLOAT || tol < MIN_FLOAT);

    return tol;
}

int raiseNumber(int number, int exponent) {
    int raisedNumber = number;
    int i;

    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return number;
    }

    for(i = 2; i <= exponent; i++) {
        raisedNumber *= number;
    }
    return raisedNumber;
}
