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

    FILE* pEmp, pNov, pTemp, pErr;

    pEmp = fopen(employeesFileName, "rb");
    pNov = fopen(noveltiesFileName, "rb");
    pTemp = fopen("archives/tmp_employees.dat", "wb");
    pErr = fopen("archives/errors.dat", "wb");

    if ( !pEmp || !pNov || !pTemp || !pErr ) {
        printf("Error opening a file.");
        return -1;
    }

    while ( !feof(pEmp) || !feof(pNov) ) {
        if () {

        } else if () {

        } else {

        }
    }

    fclose(pEmp);
    fclose(pNov);
    fclose(pTemp);
    fclose(pErr);

    return 0;
}
