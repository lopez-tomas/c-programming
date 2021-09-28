#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

int main() {
    char employeesFileName[] = "archives/employees.dat";
    char professorsFileName[] = "archives/professors.dat";
    char noveltiesFileName[] = "archives/novelties.dat";
    char tmp_professorsFileName[] = "archives/tmp_professors.dat";
    char errorsFileName[] = "archives/errors.txt";

    /*createTestEmployeesLot(employeesFileName);*/

    /*showEmployeesFile(employeesFileName);*/
    /*raiseSalary(employeesFileName, 'B');*/
    /*puts(" ------------- ");*/
    /*showEmployeesFile(employeesFileName);*/

    createTestProfessorsLot(professorsFileName);
    createTestNoveltiesLot(noveltiesFileName);

    printf("%s file:\n", professorsFileName);
    showProfessorsFile(professorsFileName);

    printf("\n\n");
    printf("%s file:\n", noveltiesFileName);
    showNoveltiesFile(noveltiesFileName);

    FILE* pEmp, *pNov, *pTemp, *pErr;
    tProfessors emp;
    tNovelties nov;
    /*tProfessors temp;*/
    /*tNovelties err;*/
    int cmp;
    char novelty;

    pEmp = fopen(employeesFileName, "rb");
    pNov = fopen(noveltiesFileName, "rb");
    pTemp = fopen(tmp_professorsFileName, "wb");
    pErr = fopen(errorsFileName, "wt");

    if ( !pEmp || !pNov || !pTemp || !pErr ) {
        printf("Error opening a file.");
        return -1;
    }

    fread(&emp, sizeof(tProfessors), 1, pEmp);
    fread(&nov, sizeof(tNovelties), 1, pNov);

    while ( !feof(pEmp) && !feof(pNov) ) {
        cmp = compareEmployees(&emp, &nov); // -> I must always pass structs by memory direction
        novelty = tolower(nov.novelty);

        if ( !cmp ) { // -> if( cmp == 0 )
            if ( novelty == 'r' ) {
                fread(&nov, sizeof(tNovelties), 1, pNov);
                fread(&emp, sizeof(tProfessors), 1, pEmp);

            } else if ( novelty == 'm' ) {
                fwrite(&nov.prof, sizeof(tProfessors), 1, pTemp);
                /*fflush(pTemp); // -> This is not necessary because we are only writing into pTemp*/
                fread(&nov, sizeof(tNovelties), 1, pNov);
                fread(&emp, sizeof(tProfessors), 1, pEmp);

            } else {
                fwrite(&emp, sizeof(tProfessors), 1, pTemp);
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
                    fwrite(&emp, sizeof(tProfessors), 1, pTemp);
                    fread(&emp, sizeof(tProfessors), 1, pEmp);
                }
            } else {
                if ( cmp > 0 ) {
                    fprintf(pErr, "%u|%s|%5.2f|%c\n", nov.prof.dni, nov.prof.completeName, nov.prof.salary, nov.novelty);
                    fwrite(&emp, sizeof(tProfessors), 1, pTemp);
                    fread(&nov, sizeof(tNovelties), 1, pNov);
                    fread(&emp, sizeof(tProfessors), 1, pEmp);
                } else {
                    fwrite(&emp, sizeof(tProfessors), 1, pTemp);
                    fread(&emp, sizeof(tProfessors), 1, pEmp);
                }
            }
        }
    }

    while ( !feof(pEmp) ) {
        fwrite(&emp, sizeof(tProfessors), 1, pTemp);
        fread(&emp, sizeof(tProfessors), 1, pEmp);
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

    fclose(pEmp);
    fclose(pNov);
    fclose(pTemp);
    fclose(pErr);

    remove(professorsFileName);
    rename(tmp_professorsFileName, professorsFileName);

    printf("\n\n%s file modified:\n", professorsFileName);
    showProfessorsFile(professorsFileName);

    printf("\n\n%s file:\n", errorsFileName);
    showErrorsFile(errorsFileName);
    printf("\n");

    return 0;
}
