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
} tProfessor;

typedef struct {
	tProfessor;
	char x;
}

int createTestEmployeesLot(const char* fileName);
int createTestProfessorsLot(const char* fileName);
int showEmployeesFile(const char* fileName); 
int raiseSalary(const char* fileName, char category);

#endif // BINARYFILES_H
