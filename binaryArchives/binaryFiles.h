#ifndef BINARYFILES_H
#define BINARYFILES_H

typedef struct {
	int dni;
	char completeName[200];
	char category;
	float salary;
	
} tEmployees;

typedef struct {
	unsigned dni;
	char completeName[200];
} tStudents;

int createTestEmployeesLot(const char* fileName);
int showEmployeesFile(const char* fileName); 
int raiseSalary(const char* fileName, char category);

#endif // BINARYFILES_H
