#include "naturalExponential.h"
#include "factorial.h"

#define MAX_FLOAT 1
#define MIN_FLOAT 0.000001

double calculateNaturalExponential(int x, float tol) {

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
