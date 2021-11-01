#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct {
    int file_number;
    char full_name[50];
    float salary;
} t_Employee;


int showEmployee(const void* vEmp);

int cmpEmployeeSalaray__asc(const void*,const void*);
int cmpEmployeeSalaray__desc(const void*,const void*);

int cmpEmployeeFullName__asc(const void*,const void*);
int cmpEmployeeFullName__desc(const void*,const void*);

int cmpEmployeeFileNumber__asc(const void*,const void*);
int cmpEmployeeFileNumber__desc(const void*,const void*);

#endif // EMPLOYEE_H
