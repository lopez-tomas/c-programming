#include <stdio.h>
#include "functions.h"

void *mem_move(void *dest, const void *orig, size_t n) {
    int i;
    void* cpy_dest = dest;

    for(i = 0; i < n; i++) {
        *(char*)cpy_dest = *(char*)orig;

        cpy_dest++; // 1 byte
        orig++;
    }

    return dest;
}

void swap(void *s1, void *s2, size_t n) {
    int i;
    char aux;

    for(i = 0; i < n; i++) {
       aux = *(char*)s2;
       *(char*)s2 = *(char*)s1;
       *(char*)s1 = aux;

       s1++;
       s2++;
    }
}

void showInteger(void* vec) {
    printf("%d\n", *(int*)vec);
}

void showFloat(void* vec) {
    printf("%5.2f\n", *(float*)vec);
}

void showVector(void* vec, size_t element, size_t numberElements, void act(void*)) {
    int i;

    for (i = 0; i < numberElements; i++) {
        act(vec);
        vec+= element;
    }
}
