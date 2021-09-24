#include <stdio.h>
#include "binaryFiles.h"

int createTestEmployeesLot(const char* fileName) {
    tEmployees emp[] = {
        { 10, "Juan", 'C', 500.0 },
        { 20, "Maria", 'A', 300.0 },
        { 30, "Pedro", 'D', 200.0 },
        { 40, "Daniel", 'B', 150.0 },
        { 50, "Jorge", 'A', 200.0 },
        { 60, "Mariana", 'X', 200.0 }
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
