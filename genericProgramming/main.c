#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

int main()
{
    int vecOri[] = {1,2,3,4,5}; // 20
    int vecDest[7]; // 28
    int vecDest2[7]; // 28

    int tamOri = sizeof(vecOri) / sizeof(int); // 10
    int tamDest = sizeof(vecDest) / sizeof(int); // 7
    int tamMAX = (tamOri > tamDest ? tamDest : tamOri);
    int cantElem;
    int i;

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

    int vec[] = {1,2,3,4};
    int vec2[] = {5,6,7,8};
    intercambio(vec, vec2, sizeof(vec));

    for(i = 0; i < sizeof(vec) / 4; i++) {
        printf("%d\t%d\n", vec[i], vec2[i]);
    }

    tAlumnos alu1 = {111111, "Carlos Tovarez"};
    tAlumnos alu2;
    intercambio(&alu1, &alu2, sizeof(tAlumnos));

    printf("\n\n%u %s\n", alu2.dni, alu2.apyn);

    return 0;
}
