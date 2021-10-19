#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int add(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

typedef int (*tOperation)(int, int);
typedef int (*tCompareFunction)(const void*, const void*);

int main() {
//    char employeesFileName[] = "archives/employees.dat";
//    char professorsFileName[] = "archives/professors.dat";
//    char noveltiesFileName[] = "archives/novelties.dat";
//    char tmp_professorsFileName[] = "archives/tmp_professors.dat";
//    char errorsFileName[] = "archives/errors.txt";
//
////    createTestEmployeesLot(employeesFileName);
////
////    showEmployeesFile(employeesFileName);
////    raiseSalary(employeesFileName, 'B');
////    puts(" ------------- ");
////    showEmployeesFile(employeesFileName);
//
//    createTestProfessorsLot(professorsFileName);
//    createTestNoveltiesLot(noveltiesFileName);
//
//    printf("%s file:\n", professorsFileName);
//    showProfessorsFile(professorsFileName);
//
//    printf("\n\n");
//    printf("%s file:\n", noveltiesFileName);
//    showNoveltiesFile(noveltiesFileName);
////
//    obtainingNewProfessorsFile(professorsFileName, noveltiesFileName, tmp_professorsFileName, errorsFileName);
////
//    printf("\n\n%s file modified:\n", professorsFileName);
//    showProfessorsFile(professorsFileName);
//
//    printf("\n\n%s file:\n", errorsFileName);
//    showErrorsFile(errorsFileName);
//    printf("\n");

    /*short int x = 1;*/
    /*char* cp = &x;*/
    /*if (*(int*)cp == 1) {*/
        /*printf("big endian");*/
    /*} else {*/
        /*printf("little endian");*/
    /*}*/

//    tEmployees emp;
//    tStudents stu;

    /*void* pFunction;*/
//    tOperation pFunction = sub;
//    printf("\nOperation: %d\n\n", pFunction(5, 9));
//
//    showFile(employeesFileName, &emp, sizeof(emp), showEmployee);
//    puts("=============================");
//    showFile(stude, &emp, sizeof(emp), showEmployee);

//    tStudents vAlu[] = {{1111111, "Hola hola"}, {222222, "chau chau"}, {33333, "hola chau"}};

    char movements_filename[] = "archives/movements.dat";
    t_Movements mov;

    createTestMovements(movements_filename);

    showFile(movements_filename, &mov, sizeof(mov), showMovement);

    return 0;
}
