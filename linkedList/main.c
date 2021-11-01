#include "main.h"

int main() {
    t_Employee employee[]       = {
        {7, "Maria Pia", 100.0},
        {16,"Sergio Beltran", 100.0},
        {1, "Juan Perez", 150.0},
        {5, "Diego Gomez", 100.0},
        {10,"Mariana Babiun", 150.0},
        {13,"Norma Gonzalez", 100.0},
        {5, "Diego Gomez", 100.0},
        {7, "Maria Pia", 90.0},
        {10,"Mariana Babuin", 100.0}
    };

    int i;

    t_LinkedList employee_list;

    createLinkedList(&employee_list);

    for(i = 0; i < sizeof(t_Employee) / sizeof(employee); i++) {
//        insertSorted(&employee_list, )
        insertInPosition(&employee_list, &employee[i], sizeof(t_Employee), cmpEmployeeFileNumber__desc);
    }

    return 0;
}
