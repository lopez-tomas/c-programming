#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) ( (x) < (y) ? (x) : (y) )

void createStack(t_Stack* stack) {
    *stack = NULL;
}

int push(t_Stack* stack, const void* data, size_t data_size) {
    t_Node* new_node = malloc(sizeof(t_Node));
    if(new_node == NULL) {
        return 0;
    }

    new_node->info = malloc(data_size);
    if(new_node->info == NULL) {
        free(new_node);
        return 0;
    }

    memcpy(new_node->info, data, data_size);
    new_node->info_size = data_size;

    if( *stack == NULL ) {
        new_node->next = new_node;
        *stack = new_node;
    } else {
        new_node->next = (*stack)->next;
        (*stack)->next = new_node;
    }

    return 1;
}

int pop(t_Stack* stack, void* data, size_t data_size) {
    t_Node* eliminate;

    if( *stack == NULL ) {
        return 0;
    }

    eliminate = (*stack)->next;

    memcpy(data, eliminate->info, MIN(eliminate->info_size, data_size));

    if( *stack == (*stack)->next ) {
        *stack = NULL;
    } else {
        (*stack)->next = eliminate->next;
    }

    // Free memory
    free(eliminate->info);
    free(eliminate);

    return 1;
}

int top(t_Stack* stack, void* data, size_t data_size) {
    if( *stack == NULL ) {
        return 0;
    }

    memcpy(data, (*stack)->next->info, MIN((*stack)->next->info_size, data_size));

    return 1;
}

int isEmpty(t_Stack* stack) {
    return *stack == NULL;
}

int isFull(t_Stack* stack, size_t data_size) {
    t_Node* test = malloc(sizeof(t_Node));
    if( test ) {
        return 1;
    }

    test->info = malloc(data_size);
    if( test->info ) {
        free(test);
        return 1;
    }

    free(test->info);
    free(test);

    return 0;
}

void emptyStack(t_Stack* stack) {
    t_Node* eliminate;

    while(*stack != NULL) {
        eliminate = (*stack)->next;
        (*stack)->next = eliminate->next;

        free(eliminate->info);
        free(eliminate);
    }
}
