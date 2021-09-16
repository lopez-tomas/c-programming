#include "archives.h"

int openFile(FILE** pf, char* fileName, char* mode) {
    *pf = fopen(fileName, mode);

    return pf != NULL;
}
