#include "archives.h"

#define STUDENTS 10
#define TAM 70

int openFile(FILE** pf, char* fileName, char* mode) {
    *pf = fopen(fileName, mode);

    return pf != NULL;
}

int loadStudentsTestLot(char* fileName) {
    char studentsLot[STUDENTS][TAM] =
                                    {
                                    "11222333|Oscar Vacilante|M|10.0",
                                    "22000444|Jose Luis Aranguren|M|8.0",
                                    "10010010|Maria Cachantun|F|9.4",
                                    "41398819|Tomas Lopez|M|7.8",
                                    "44273918|Ines Toledo|F|6.3",
                                    "10010010|Maria Pia|F|4.5",
                                    "29183718|Sebastian Toretto|M|8.0",
                                    "29184791|Constanza Ortiz|F|8.0",
                                    "57281038|Pipo Bustamante|M|2.1",
                                    "38194819|Marcos Pipirola|M|5.7"
                                    };
    FILE* pf;
    int i;

    pf = fopen(fileName, "wt");
    if(!pf) {
        return 0;
    }

    for(i = 0; i < STUDENTS; i++) {
        fprintf(pf, "%s\n", studentsLot[i]);
    }
    fclose(pf);

    return 1;
}
