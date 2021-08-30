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

int isInFibonacci(int number) {
    int firstOne = 0,
        secondOne = 1,
        result,
        answer = 0,
        i;

    for(i = 1; i <= number; i++) {
        result = firstOne + secondOne;
        firstOne = secondOne;
        secondOne = result;

        if (result == number) {
            return answer = 1;
        }
    }
    return answer;
}

void printAnswerFibonacci(int number, int answer) {
    if (answer) {
        printf("The number %d is in Fibonacci Sequence.", number);
    } else {
        printf("The number %d isn't in Fibonacci Sequence.", number);
    }
}
