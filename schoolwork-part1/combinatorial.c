#include "combinatorial.h"

int enterNumberN() {
    int n;

    do {
        printf("Enter an integer 'n' [ >= 0 ]: ");
        scanf(" %d", &n);
    } while( n < 0 );

    return n;
}

int enterNumberM(int n) {
    int m;

    do {
        printf("Enter an integer 'm' [ >= %d ]: ", n);
        scanf(" %d", &m);
    } while ( m < n );

    return m;
}


