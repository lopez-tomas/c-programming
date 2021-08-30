#include <stdio.h>

#include "combinatorial.h"
#include "factorial.h"

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

unsigned long long int combinatorialOf(int n, int m) {
    double combinatorial,
           mFactored,
           nFactored,
           diffFactored;

    mFactored = factorialOf(m);
    nFactored = factorialOf(n);
    diffFactored = factorialOf(m - n);

    combinatorial = (mFactored) / (nFactored * diffFactored);

    return combinatorial;
}



