#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    char employeesFileName[] = "archives/employees.dat";
    char noveltiesFileName[] = "archives/novelties.dat";

    /*createTestEmployeesLot(employeesFileName);*/

    /*showEmployeesFile(employeesFileName);*/
    /*raiseSalary(employeesFileName, 'B');*/
    /*puts(" ------------- ");*/
    /*showEmployeesFile(employeesFileName);*/

    createTestProfessorsLot(employeesFileName);
    createTestNoveltiesLot(noveltiesFileName);

    FILE* pEmp, *pNov, *pTemp, *pErr;
    tProfessors emp;
    tNovelties nov;
    tProfessors temp;
    tNovelties err;
    int cmp;

    pEmp = fopen(employeesFileName, "rb");
    pNov = fopen(noveltiesFileName, "rb");
    pTemp = fopen("archives/tmp_employees.dat", "wb");
    pErr = fopen("archives/errors.dat", "wb");

    if ( !pEmp || !pNov || !pTemp || !pErr ) {
        printf("Error opening a file.");
        return -1;
    }

    fread(&emp, sizeof(tEmployees), 1, pEmp);
    fread(&nov, sizeof(tNovelties), 1, pNov);
    while ( !feof(pEmp) || !feof(pNov) ) {
        cmp = compareEmployees(&emp, &nov.prof); // -> I must always pass structs by memory direction

        if ( !cmp ) { // -> if( cmp == 0 )
            if ( nov.novelty == 'r' );
                fread(&emp, sizeof(tEmployees), 1, pEmp);
                fread(&nov, sizeof(tNovelties), 1, pNov);

            } else if ( nov.novelty == 'm' ) {
                fwrite(&nov.prof, sizeof(tEmployees), 1, pTemp);
                /*fflush(pTemp);*/

            } else {
                fwrite(&nov, sizeof(tNovelties), 1, pErr); // change it to use fprintf (must change extension of error file to be a text)
                /*fflush(pErr);*/
            }
        } else {
            if ( nov.novelty == 'a' ) {

            }
        }
    }

    fclose(pEmp);
    fclose(pNov);
    fclose(pTemp);
    fclose(pErr);

    return 0;
}
