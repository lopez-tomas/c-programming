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

    // Testing showVector() function with showInteger() & showFloat() functions:
    int intVec[] = {1, 2, 3, 4, 5};
    float floatVec[] = {0.1, 0.2, 0.3};
    t_Students students[] = {
        {25350252, "Modric, Luka", 10.0},
        {34350252, "Nolan, Cristian", 7.33},
        {45350256, "Robertone, Leandro", 4.66},
        {30350252, "Sanchez, Beto", 8.50},
        {29350252, "Sanchez, Hugo", 4.0},
        {28350256, "Torres, Johana", 3.33},
        {35350256, "Xasas, Jorge", 9.66}
    };

//    printf("intVec:\n");
//    showVector(intVec, sizeof(int), sizeof(intVec) / sizeof(int), showInteger);
//
//    printf("\nfloatVec:\n");
//    showVector(floatVec, sizeof(float), sizeof(floatVec) / sizeof(float), showFloat);
//
//    printf("\nstudents:\n");
//    showVector(students, sizeof(t_Students), sizeof(students) / sizeof(t_Students), showStudent);

    int genericIntVec[] = {3,9,5,1,7,2};
    float genericFloatVec[] = {3.3, 9.9, 5.5, 1.1, 7.7, 2.2};

    /// INT
//    showVector(genericIntVec, sizeof(int), sizeof(genericIntVec) / sizeof(int), showInteger);
//
//    sortSelection(genericIntVec, sizeof(genericIntVec) / sizeof(int), sizeof(int), descendentIntegers);
//    printf("\n\n");
//
//    showVector(genericIntVec, sizeof(int), sizeof(genericIntVec) / sizeof(int), showInteger);
//
//    sortSelection(genericIntVec, sizeof(genericIntVec) / sizeof(int), sizeof(int), ascendentIntegers);
//    printf("\n\n");
//
//    showVector(genericIntVec, sizeof(int), sizeof(genericIntVec) / sizeof(int), showInteger);

    /// FLOAT
    printf("genericFloatVec[] without changes:\n");
    showVector(genericFloatVec, sizeof(float), sizeof(genericFloatVec) / sizeof(int), showFloat);

    sortSelection(genericFloatVec, sizeof(genericFloatVec) / sizeof(float), sizeof(float), descendentFloats);
    printf("\n\n");
    printf("genericFloatVec[] sorted descendingly:\n");
    showVector(genericFloatVec, sizeof(float), sizeof(genericFloatVec) / sizeof(float), showFloat);

    sortSelection(genericFloatVec, sizeof(genericFloatVec) / sizeof(float), sizeof(float), ascendentFloats);
    printf("\n\n");
    printf("genericFloatVec[] sorted ascendingly:\n");
    showVector(genericFloatVec, sizeof(float), sizeof(genericFloatVec) / sizeof(float), showFloat);

    return 0;
}
