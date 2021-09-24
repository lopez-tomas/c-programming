#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    char fileName[] = "archives/employees.dat";

    createTestEmployeesLot(fileName);

    showEmployeesFile(fileName);
    raiseSalary(fileName, 'B');
    puts(" ------------- ");
    showEmployeesFile(fileName);

    return 0;
}
