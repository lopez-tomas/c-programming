#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "../employee.h"

void createLinkedList(t_LinkedList* list) {
    *list = NULL;
}

int insertInPosition(t_LinkedList* list, const void* data, size_t data_size, const unsigned position) {
    unsigned pos = 0;

    t_Node* new_node = malloc(sizeof(t_Node));
    if( !new_node ) {
        return 0;
    }

    new_node->info = malloc(data_size);
    if( new_node->info ) {
        free(new_node);
        return 0;
    }

    memcpy(new_node->info, data, data_size);
    new_node->info_size = data_size;

    while( *list && pos < position) {
        list = &(*list)->next;
        pos++;
    }

    new_node->next = *list;
    *list = new_node;

    return 1;
}

void filter(t_LinkedList* list, int action(const void*)) {
    t_Node* aux;

    while( *list ) { // list != NULL ???
        if( action((*list)->info) ) {
            aux = *list;

            *list = aux->next;
            free(aux->info);
            free(aux);
        }
        list = &(*list)->next;
    }
}

int salaryMinorThan(const void* vPunt) {
    t_Employee* emp = (t_Employee*)vPunt;

    return emp->salary < 100.0;
}
