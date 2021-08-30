#include <stdio.h>
#include "fibonacci.h"

int enterInteger() {
    int num;
    do {
        printf("Enter an integer ( > 0 ): ");
        scanf(" %d", &num);
    } while(num <= 0);

    return num;
}

int isPerfectSquare(int number) {
    int answer = 0,
        i;

    for (i = 1; i < number; i++) {
        if ( i*i == number ) {
            answer = 1;
            return answer;
        }
    }
    return answer;
}

void isInFibonacci(int number, int answer) {
    if (answer) {
        printf("The number %d is in Fibonacci Series.");
    } else {
        printf("The number %d isn't in Fibonacci Series.");
    }
}
