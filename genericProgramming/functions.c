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
