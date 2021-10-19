#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "binaryFiles.h"

#define LINE_LENGTH 500

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
        {50, "Beltran Sergio", 200.0},
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

int createTestMovements(const char* fileName) {
    t_Movements mov[] = {
        {10000, 'D', 300.0},
        {10000, 'E', 250.0},
        {10000, 'E', 300.0},
        {30000, 'E', 250.0},
        {30000, 'D', 1550.0},
        {10000, 'D', 800.0},
        {12200, 'E', 150.0},
        {12200, 'E', 200.0},
        {11110, 'D', 200.0},
        {11110, 'E', 2580.50}
    };

    FILE* pf = fopen(fileName, "wb");
    if (!pf) {
        return 0;
    }

    fwrite(mov, sizeof(mov), 1, pf);

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

int showProfessorsFile(const char* fileName) {
    FILE* pf = fopen(fileName, "rb");
    tProfessors prof;

    if(!pf) {
        return 0;
    }

    fread(&prof, sizeof(prof), 1, pf);
    while(!feof(pf)) {
        printf("%u %s %5.2f\n", prof.dni, prof.completeName, prof.salary);
        fread(&prof, sizeof(prof), 1, pf);
    }

    fclose(pf);
    return 1;
}

int showNoveltiesFile(const char* fileName) {
    FILE* pf = fopen(fileName, "rb");
    tNovelties nov;

    if(!pf) {
        return 0;
    }

    fread(&nov, sizeof(nov), 1, pf);
    while(!feof(pf)) {
        printf("%u %s %5.2f %c\n", nov.prof.dni, nov.prof.completeName, nov.prof.salary, nov.novelty);

        fread(&nov, sizeof(nov), 1, pf);
    }

    fclose(pf);
    return 1;
}

int showErrorsFile(const char* fileName) {
    tNovelties err;
    char line[LINE_LENGTH];
    int line_length = LINE_LENGTH - 1;

    FILE* pf = fopen(fileName, "rt");

    if (!pf) {
        return 0;
    }

    while ( fgets(line, line_length, pf) ) {
        sscanf(line, "%u|%[^|]|%f|%c", &err.prof.dni, err.prof.completeName, &err.prof.salary, &err.novelty);
        fprintf(stdout, "%u|%s|%5.2f|%c", err.prof.dni, err.prof.completeName, err.prof.salary, err.novelty);
    }
    fclose(pf);

    return 1;
}

void showEmployee(void* pvEmp) {
    tEmployees* emp = (tEmployees *)pvEmp; // -> working with pointers
    //tEmployees emp = *(tEmployees *)pvEmp; -> working in local
    printf("%u %s %c %5.2f\n", emp->dni, emp->completeName, emp->category, emp->salary); // -> working with pointers
    //printf("%u %s %c %5.2f\n", emp.dni, emp.completeName, emp.category, emp.salary);
}

void showStudent(void* pvStu) {
    tStudents* stu = (tStudents *)pvStu;
    printf("%u %s\n", stu->dni, stu->completeName);
}

void showProfessor(void* pvProf) {
    tProfessors* prof = (tProfessors *)pvProf;
    printf("%u %s %5.2f\n", prof->dni, prof->completeName, prof->salary);
}

void showMovement(void* pvMov) {
    t_Movements* mov = (t_Movements *)pvMov;
    printf("%.5u | %c | %5.2f\n", mov->account_number, mov->movement, mov->value);
}

int showFile(const char* fileName, void* buffer, size_t size, void act(void*)) {
    FILE* pf = fopen(fileName, "rb");
    if(!pf) {
        return 0;
    }
    fread(buffer, size, 1, pf);
    while(!feof(pf)) {
        act(buffer);
        fread(buffer, size, 1, pf);
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

int obtainingNewProfessorsFile(const char* professorsFileName, const char* noveltiesFileName, const char* tmp_professorsFileName, const char* errorsFileName) {
    FILE* pProf, *pNov, *pTemp, *pErr;
    tProfessors prof;
    tNovelties nov;
    int cmp;
    char novelty;

    pProf = fopen(professorsFileName, "rb");
    if ( !pProf ) {
        printf("Error opening %s file.", professorsFileName);
        return -1;
    }

    pNov = fopen(noveltiesFileName, "rb");
    if ( !pNov ) {
        printf("Error opening %s file.", noveltiesFileName);
        fclose(pProf);
        return -2;
    }

    pTemp = fopen(tmp_professorsFileName, "wb");
    if ( !pTemp ) {
        printf("Error creating %s file.", tmp_professorsFileName);
        fclose(pProf);
        fclose(pNov);
        return -3;
    }

    pErr = fopen(errorsFileName, "wt");
    if ( !pErr ) {
        printf("Error creating %s file.", errorsFileName);
        fclose(pProf);
        fclose(pNov);
        fclose(pTemp);
        return -4;
    }

    fread(&prof, sizeof(tProfessors), 1, pProf);
    fread(&nov, sizeof(tNovelties), 1, pNov);

    while ( !feof(pProf) && !feof(pNov) ) {
        cmp = compareEmployees(&prof, &nov); // -> I must always pass structs by memory direction
        novelty = tolower(nov.novelty);

        if ( !cmp ) { // -> if( cmp == 0 )
            if ( novelty == 'r' ) {
                fread(&nov, sizeof(tNovelties), 1, pNov);
                fread(&prof, sizeof(tProfessors), 1, pProf);

            } else if ( novelty == 'm' ) {
                fwrite(&nov.prof, sizeof(tProfessors), 1, pTemp);
                /*fflush(pTemp); // -> This is not necessary because we are only writing into pTemp*/
                fread(&nov, sizeof(tNovelties), 1, pNov);
                fread(&prof, sizeof(tProfessors), 1, pProf);

            } else {
                fwrite(&prof, sizeof(tProfessors), 1, pTemp);
                /*fwrite(&nov, sizeof(tNovelties), 1, pErr); // -> If we are using .txt files, we must change this to use fprintf()*/
                fprintf(pErr, "%u|%s|%5.2f|%c\n", nov.prof.dni, nov.prof.completeName, nov.prof.salary, nov.novelty);
                fread(&nov, sizeof(tNovelties), 1, pNov);
            }
        } else {
            if ( novelty == 'a' ) {
                if ( cmp > 0 ) {
                    fwrite(&nov.prof, sizeof(tProfessors), 1, pTemp);
                    fread(&nov, sizeof(tNovelties), 1, pNov);

                } else {
                    fwrite(&prof, sizeof(tProfessors), 1, pTemp);
                    fread(&prof, sizeof(tProfessors), 1, pProf);
                }
            } else {
                if ( cmp > 0 ) {
                    fprintf(pErr, "%u|%s|%5.2f|%c\n", nov.prof.dni, nov.prof.completeName, nov.prof.salary, nov.novelty);
                    fwrite(&prof, sizeof(tProfessors), 1, pTemp);
                    fread(&nov, sizeof(tNovelties), 1, pNov);
                    fread(&prof, sizeof(tProfessors), 1, pProf);
                } else {
                    fwrite(&prof, sizeof(tProfessors), 1, pTemp);
                    fread(&prof, sizeof(tProfessors), 1, pProf);
                }
            }
        }
    }

    while ( !feof(pProf) ) {
        fwrite(&prof, sizeof(tProfessors), 1, pTemp);
        fread(&prof, sizeof(tProfessors), 1, pProf);
    }

    while ( !feof(pNov) ) {
        novelty = tolower(nov.novelty);
        if (novelty == 'a') {
            fwrite(&nov.prof, sizeof(tProfessors), 1, pTemp);
        } else {
            fprintf(pErr, "%u|%s|%5.2f|%c\n", nov.prof.dni, nov.prof.completeName, nov.prof.salary, nov.novelty);
        }
        fread(&nov, sizeof(tNovelties), 1, pNov);
    }

    fclose(pProf);
    fclose(pNov);
    fclose(pTemp);
    fclose(pErr);

    remove(professorsFileName);
    rename(tmp_professorsFileName, professorsFileName);

    return 0;
}
