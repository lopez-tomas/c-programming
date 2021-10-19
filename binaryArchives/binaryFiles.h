#ifndef BINARYFILES_H
#define BINARYFILES_H

#include <stdlib.h>

typedef struct {
	unsigned dni;
	char completeName[200];
	char category;
	float salary;
} tEmployees;

typedef struct {
	unsigned dni;
	char completeName[200];
} tStudents;

typedef struct {
	unsigned dni;
	char completeName[200];
	float salary;
} tProfessors;

typedef struct {
	tProfessors prof;
	char novelty; // a: add; r: remove; m: modify
} tNovelties;

typedef struct {
    unsigned account_number;
    char movement;
    float value;
} t_Movements;

int createTestEmployeesLot(const char* fileName);
int createTestProfessorsLot(const char* fileName);
int createTestNoveltiesLot(const char* fileName);

int createTestMovements(const char* fileName);

int showEmployeesFile(const char* fileName);
int showProfessorsFile(const char* fileName);
int showNoveltiesFile(const char* fileName);
int showErrorsFile(const char* fileName);

void showEmployee(void* pvEmp);
void showStudent(void* pvStu);
void showProfessor(void* pvProf);
void showMovement(void* pvMov);

int showFile(const char* fileName, void* buffer, size_t size, void act(void*));

int raiseSalary(const char* fileName, char category);
int compareEmployees(const tProfessors* a, const tNovelties* b);
int obtainingNewProfessorsFile(const char* professorsFileName, const char* noveltiesFileName, const char* tmp_professorsFileName, const char* errorsFileName);

#endif // BINARYFILES_H
