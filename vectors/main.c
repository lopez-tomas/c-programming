#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main() {

    int vec1[5] = {1,2,3,4,5};
    int vec2[5] = {10,11,12}; // compiler completes with 0s into pos 3 and pos 4.
    int vec3[5] = {21,22,23,24,25,26,27,28}; // compiler does not take in account.
    int vec4[] = {31, 32, 33}; // compiler assings TAM.
    //int vec5[];
    //int vec6[5] = {41, , 42, 43, 44}; it can't assign a 0 in pos 1 because I put more values after.
    int vec7[5] = {0};
    //vec3[6] = 7;

    return 0;
}
