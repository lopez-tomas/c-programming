#include "combinatorial.h"

int enterNumberN() {
    int n;

    do {
        printf("Enter an integer [ >= 0 ]: ");
        scanf(" %d", &n);
    } while( n < 0 );

    return n;
}

