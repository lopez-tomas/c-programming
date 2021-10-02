#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

char* special_strcpy(char* dest, char* orig) {
    int numChars = strlen(orig) + 1;

    dest = malloc(numChars);

    return dest == NULL ? NULL : strcpy(dest, orig);
}

void* mem_move(void* s1, const void* s2, size_t sizeElement) {
    return s1;
}
