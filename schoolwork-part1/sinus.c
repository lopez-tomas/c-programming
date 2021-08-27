#include "sinus.h"
#include "naturalExponential.h"
#include "factorial.h"

double sinusOf(int number, double tol) {
    int exponent = 3,
        numberRaised;
    double factoredNumber,
           term = number;

    do {
        numberRaised = raiseNumber(number, exponent);
        factoredNumber = factorialOf(exponent);

        term -= numberRaised / factoredNumber;

        exponent += 2;
    } while( absolute(term) > tol );

    return term;
}

double absolute(double value) {
    return value *= -1;
}
