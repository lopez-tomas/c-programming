#include <stdio.h>
#include <string.h>
#include "binaryFiles.h"

int createTestEmployeesLot(const char* fileName) {
    tEmployees emp[] = {
        {10, "Juan", 'C', 500.0},
        {20, "Maria", 'A', 300.0},
        {30, "Pedro", 'D', 200.0},
        {40, "Daniel", 'B', 150.0},
        {50, "Jorge", 'A', 200.0},
        {60, "Mariana", 'X', 200.0}
    };

    FILE* pf = fopen(fileName, "wb");
    if (!pf) {
        return 0;
    }

    // Option 1: sizeof(emp) == sizeof(tEmployees) * 6
    fwrite(emp, sizeof(emp), 1, pf);

    // Option 2
    //fwrite(emp, sizeof(tEmployees), sizeof(emp) / sizeof(tEmployees), pf);

    // Option 3
    // while...

    fclose(pf);
    return 1;
}

int createTestProfessorsLot(const char* fileName) {
    tProfessors prof[] = {
        {20, "Abala Maria", 200.0},
        {19, "Abala Monica", 300.0},
        {50, "Beltan Sergio", 200.0},
        {89, "Cale Damian", 200.0},
        {99, "Cale Damian", 200.0},
        {10, "Delos German", 150.0}
    };

    FILE* pf = fopen(fileName, "wb");
    if (!pf) {
        return 0;
    }

    fwrite(prof, sizeof(prof), 1, pf);

    fclose(pf);
    return 1;
}

int createTestNoveltiesLot(const char* fileName) {
    tNovelties nov[] = {
        {{17, "Abala Ana", 300.0}, 'a'},
        {{20, "Abala Maria", 250.0}, 'm'},
        {{33, "Asraliam Jorge", 300.0}, 'a'},
        {{55, "Badom Daniel", 250.0}, 'r'},
        {{90, "Cale Damian", 800.0}, 'a'},
        {{99, "Cale Damian", 800.0}, 'm'},
        {{10, "Delos German", 150.0}, 'r'},
        {{25, "Lagos Julian", 200.0}, 'a'}
    };

    FILE* pf = fopen(fileName, "wb");
    if (!pf) {
        return 0;
    }

    fwrite(nov, sizeof(nov), 1, pf);

    fclose(pf);
    return 1;
}

int showEmployeesFile(const char* fileName) {
    FILE* pf = fopen(fileName, "rb");
    tEmployees emp;

    if(!pf) {
        return 0;
    }

    fread(&emp, sizeof(emp), 1, pf);
    while(!feof(pf)) {
        printf("%u %s %c %5.2f\n", emp.dni, emp.completeName, emp.category, emp.salary);

        fread(&emp, sizeof(emp), 1, pf);
    }

    fclose(pf);
    return 1;
}

int raiseSalary(const char* fileName, char category) {
    FILE* pf = fopen(fileName, "r+b");
    tEmployees emp;

    if(!pf) {
        return 0;
    }

    fread(&emp, sizeof(emp), 1, pf);
    while (!feof(pf)) {
        if (emp.category == category) {
            emp.salary *= 1.1;

            fseek(pf, -sizeof(emp), SEEK_CUR);
            fwrite(&emp, sizeof(emp), 1, pf);
            fseek(pf, 0L, SEEK_CUR); // -> I must ALWAYS do this if I'm going to read & write / write & read.
            //fflush(pf); -> I can do this too rather than using fseek again.
        }

        fread(&emp, sizeof(emp), 1, pf);
    }

    fclose(pf);
    return 1;
}

int compareEmployees(const tProfessors* a, const tNovelties* b) {
    int nameCmp = strcmp(a->completeName, b->prof.completeName);

    if ( nameCmp == 0 ) {
        return ( a->dni - b->prof.dni );
    }

    return nameCmp;
}
