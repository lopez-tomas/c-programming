#include <stdio.h>

#include "sinus.h"
#include "naturalExponential.h"
#include "factorial.h"

double sinusOf(int number, double tol) {
    int exponent = 3,
        numberRaised,
        flag = 1;
    double factoredNumber,
           term,
           sinus = number; // sin(1) = 0.8414709848079

    do {
        numberRaised = raiseNumber(number, exponent);
        factoredNumber = factorialOf(exponent);
        exponent += 2;

        if( flag ) {
            term = (float)numberRaised / factoredNumber;
            sinus -= term;
            flag = 0;
        } else {
            term = (float)numberRaised / factoredNumber;
            sinus += term;
            flag = 1;
        }
    } while( term > tol );

    return sinus;
}

int numberForSinus() {
    int num;

    printf("Enter a number to find its sinus: ");
    scanf(" %d", &num);

    return num;
}

double absolute(double value) {
    return value *= -1;
}
