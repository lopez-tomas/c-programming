#include "fibonacci.h"

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
