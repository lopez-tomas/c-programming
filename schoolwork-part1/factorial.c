#include "factorial.h"

double factorialOf(int x) {
    double factorial = x; // user's number assigned as initial value of its factorial.

    if (x <= 1) {
        factorial = 1;
    } else {
        for(int i = 1; i < x; i++) {
            factorial *= (x - i);
        }
    }
    return factorial;
}
