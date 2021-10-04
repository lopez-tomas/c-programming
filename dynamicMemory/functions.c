#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

char* special_strcpy(char* dest, const char* orig) {
    int numChars = strlen(orig) + 1;

    dest = calloc(numChars, char);

    return dest == NULL ? NULL : strcpy(dest, orig);
}

void* mem_move(void* s1, const void* s2, size_t numberElements) {
    return s1;
}
