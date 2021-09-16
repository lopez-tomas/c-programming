#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#define LINE_DIM 80

int main() {
    FILE* pArchive;
    char fileName[] = "archives/test.txt";
    char mode[] = "rt";
    char line[LINE_DIM];

//    FILE* pf = fopen("archives/test.txt", "rt");
//    if (!pf) {
//        printf("Archive does not exist.");
//        return 100;
//    }
//
//    while( fgets(line, LINE_DIM - 1, pf) ) {
//        printf("%s", line);
//    }
//
//    fclose(pf);

    if ( openFile(&pArchive, fileName, mode) ) {
        printf("%s was opened.\n\n", fileName);
        printf("Content:\n");

        while( fgets(line, LINE_DIM - 1, pArchive) ) {
            printf("%s", line);
        }
    } else {
        printf("%s could not be opened.", fileName);
        return 100;
    }
    fclose(pArchive);

    return 0;
}
