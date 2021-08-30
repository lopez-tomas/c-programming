#include <stdio.h>
#include "exercise7.h"

int numberClassification(int number) {
    int i,
        result = 0;

    for(i = 1; i < number; i++) {
        if(number % i == 0) {
            result += i;
        }
    }

    return (result == number) ? 0 : ((result < number) ? 1 : 2); // 0 = Perfect; 1 = Deficient; 2 = Abundant
}

void printClassification(int number, int classification) {
    if (classification == 0) {
        printf("The number %d is PERFECT.", number);
    } else if (classification == 1) {
        printf("The number %d is DEFICIENT.", number);
    } else {
        printf("The number %d is ABUNDANT.", number);
    }
}
