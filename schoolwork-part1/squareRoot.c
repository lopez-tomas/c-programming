#include <stdio.h>
#include "squareRoot.h"

double squareRootOf(int number, double tol) {

}

int numberForRoot() {
    int num;

    do {
        printf("Enter a positive number [ >= 1 ]: ");
        scanf(" %d", &num);
    } while(num < 1);

    return num;
}
