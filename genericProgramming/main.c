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

    do {
        printf("Cuantos enteros quiere copiar?\n");
        scanf(" %d", &cantElem);
    } while (cantElem > tamMAX);

    memmove(vecDest, vecOri, cantElem * tamMAX);
    printf("\nmemmove() function:\n");

    tamDest = cantElem;
    for(i = 0; i < tamDest; i++) {
        printf("%d\n", vecDest[i]);
    }

    mem_move(vecDest2, vecOri, cantElem * tamMAX);
    printf("\nMy memmove() function:\n");
    for(i = 0; i < tamDest; i++) {
        printf("%d\n", vecDest[i]);
    }
    
    return 0;
}
