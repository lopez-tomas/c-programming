#ifndef BINARYFILES_H
#define BINARYFILES_H

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

int createTestEmployeesLot(const char* fileName);
int createTestProfessorsLot(const char* fileName);
int createTestNoveltiesLot(const char* fileName);
int showEmployeesFile(const char* fileName);
int showProfessorsFile(const char* fileName);
int raiseSalary(const char* fileName, char category);
int compareEmployees(const tProfessors* a, const tNovelties* b);

#endif // BINARYFILES_H
