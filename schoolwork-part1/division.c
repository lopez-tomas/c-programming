#include <stdio.h>
#include "division.h"


int enterNumberA() {
    int num;

    printf("Enter number A (it could be 0): ");
    scanf(" %d", &num);

    return num;
}

int enterNumberB() {
    int num;

    do {
        printf("Enter number B (it couldn't be 0): ");
        scanf(" %d", &num);
    } while(num == 0);

    return num;
}

int obtainQuotient(int numberA, int numberB) {
    if(numberA == 0) {
        return 0;
    }

    return numberA / numberB
}

int obtainRemainder(int numberA int numberB) {
    return numberA % numberB;
}
