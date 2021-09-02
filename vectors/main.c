#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#define TAM_INT sizeof(int)

int main() {
    int vec[] = {1,2,3,4,5,6,7};
    int cant = 7;
//    printf("%p\n", &vec);
    printf("Vector vec[]: \n\n");
    printArray(vec, cant, sizeof(vec) / TAM_INT);

    int vecToFill[100] = {1, 2, 3};
    int cantElements = 3;

    printf("\nVector vecToFill[]: \n\n");
    printArray(vecToFill, cantElements, sizeof(vecToFill) / TAM_INT);


    cantElements = fillArray(vecToFill, cantElements, sizeof(vecToFill) / TAM_INT);
    printf("\nVector vecToFill[]: \n\n");
    printArray(vecToFill, cantElements, sizeof(vecToFill) / TAM_INT);

    cantElements = fillArray(vecToFill, cantElements, sizeof(vecToFill) / TAM_INT);
    printf("\nVector vecToFill[]: \n\n");
    printArray(vecToFill, cantElements, sizeof(vecToFill) / TAM_INT);


    return 0;
}
