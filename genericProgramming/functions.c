#include <stdio.h>
#include "functions.h"

void *mem_move(void *dest, const void *orig, size_t n) {
    int i = 0;
    void* cpy_dest = dest;

    while (i < n) {
        *(char*)cpy_dest = *(char*)orig;

        cpy_dest++; // 1 byte
        orig++;
        i++;
    }

    return dest;
}

void swap(void *s1, void *s2, size_t n) {
    int i = 0;
    char aux;

    while (i < n) {
       aux = *(char*)s2;
       *(char*)s2 = *(char*)s1;
       *(char*)s1 = aux;

       s1++;
       s2++;
       i++;
    }
}

void showInteger(void* vec) {
    printf("%d\n", *(int*)vec);
}

void showFloat(void* vec) {
    printf("%5.2f\n", *(float*)vec);
}
