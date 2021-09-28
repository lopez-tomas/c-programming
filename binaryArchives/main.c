#include <stdio.h>
#include <stdlib.h>
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

    obtainingNewProfessorsFile(professorsFileName, noveltiesFileName, tmp_professorsFileName, errorsFileName);

    printf("\n\n%s file modified:\n", professorsFileName);
    showProfessorsFile(professorsFileName);

    printf("\n\n%s file:\n", errorsFileName);
    showErrorsFile(errorsFileName);
    printf("\n");

    short int x = 1;
    char* cp = &x;
    if (*(int*)cp == 1) {
        printf("big endian");
    } else {
        printf("little endian");
    }

    return 0;
}
