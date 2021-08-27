#include <stdio.h>
#include "squareRoot.h"

double squareRootOf(int number, double tol) {
    double firstTerm,
           secondTerm = 1.0,
           difference;

    do {
        firstTerm = secondTerm;
        secondTerm = ( firstTerm + (number / firstTerm) ) / 2;
        difference = secondTerm - firstTerm;
    } while( difference < tol );

    return secondTerm;
}

int numberForRoot() {
    int num;

    do {
        printf("Enter a positive number [ >= 1 ]: ");
        scanf(" %d", &num);
    } while(num < 1);

    return num;
}
