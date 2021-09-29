#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

int main() {
    // Testing memmove() & mem_move() [which is my implemention]
//    int vecOri[] = {1,2,3,4,5}; // 20
//    int vecDest[7]; // 28
//    int vecDest2[7]; // 28
//
//    int tamOri = sizeof(vecOri) / sizeof(int); // 10
//    int tamDest = sizeof(vecDest) / sizeof(int); // 7
//    int tamMAX = (tamOri > tamDest ? tamDest : tamOri);
//    int cantElem;
//    int i;

    /*do {*/
        /*printf("Cuantos enteros quiere copiar?\n");*/
        /*scanf(" %d", &cantElem);*/
    /*} while (cantElem > tamMAX);*/

    /*memmove(vecDest, vecOri, cantElem * tamMAX);*/
    /*printf("\nmemmove() function:\n");*/

    /*tamDest = cantElem;*/
    /*for(i = 0; i < tamDest; i++) {*/
        /*printf("%d\n", vecDest[i]);*/
    /*}*/

    /*mem_move(vecDest2, vecOri, cantElem * tamMAX);*/
    /*printf("\nMy memmove() function:\n");*/
    /*for(i = 0; i < tamDest; i++) {*/
        /*printf("%d\n", vecDest[i]);*/
    /*}*/

    // Testing swap() function
//    int vec[] = {1,2,3,4};
//    int vec2[] = {5,6,7,8};
//    int j;
//    swap(vec, vec2, sizeof(vec));
//
//    for(j = 0; j < sizeof(vec) / 4; j++) {
//        printf("%d\t%d\n", vec[j], vec2[j]);
//    }
//
//    tAlumnos alu1 = {111111, "Carlos Tovarez"};
//    tAlumnos alu2;
//    swap(&alu1, &alu2, sizeof(tAlumnos));
//
//    printf("\n\n%u %s\n", alu2.dni, alu2.apyn);

    // Testing showVector() function with showInt() & showFloat() functions:
    int intVec[] = {1, 2, 3, 4, 5};
    float floatVec[] = {0.1, 0.2, 0.3};

    printf("intVec:\n");
    showVector(intVec, sizeof(int), sizeof(intVec) / sizeof(int), showInteger);

    printf("\nfloatVec:\n");
    showVector(floatVec, sizeof(float), sizeof(floatVec) / sizeof(float), showFloat);

    return 0;
}
