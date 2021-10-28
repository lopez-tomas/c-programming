#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#define LINE_DIM 80

typedef struct {
    int dni;
    char fullName[100];
    char department;
    float promedy;
}tStudents;

int main() {
    FILE* pArchive;
    char fileName[] = "archives/test.txt";
    char mode[] = "rt";
    char line[LINE_DIM];

    tStudents student[10];
    FILE* pStudents;
    char studentsFile[] = "archives/students.txt";
    char lineStudent[200];

//    FILE* pf = fopen("archives/test.txt", "rt");
//    if (!pf) {
//        printf("Archive does not exist.");
//        return 100;
//    }
//
//    while( fgets(line, LINE_DIM - 1, pf) ) {
//        printf("%s", line);
//    }
//
//    fclose(pf);

//    if ( openFile(&pArchive, fileName, mode) ) {
//        printf("%s was opened.\n\n", fileName);
//        printf("Content:\n");
//
//        while( fgets(line, LINE_DIM - 1, pArchive) ) {
//            printf("%s", line);
//        }
//    } else {
//        printf("%s could not be opened.", fileName);
//        return 100;
//    }
//    fclose(pArchive);

//    printf("\n\n%d %d %d %d \nTotal = %d", sizeof(student.dni), sizeof(student.fullName), sizeof(student.department), sizeof(student.promedy), sizeof(student));

    if (loadStudentsTestLot(studentsFile) == 0) {
        printf("The file could not be created.");
        return 300;
    }

    printf("The file was created succesfully.");

    pStudents = fopen(studentsFile, "rt");

    while (fgets(line, 199, pStudents)) {
        sscanf(lineStudent, "%d|%[^|]|%c|%f", student.dni, student->fullName, student.department, student.promedy);
        fprintf(stdout, "%s|%c|%f", student.dni, student.fullName, student.department, student.promedy);
    }
    fclose(pStudents);

    return 0;
}
