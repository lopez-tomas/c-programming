#include <string.h>
#include "Stack.h"

#define MIN(x, y) ( (x) < (y) ? (x) : (y) )

void createStack(t_Stack* stack) {
    *stack = NULL;
}

int push(t_Stack* stack, const void* data, size_t data_size) {
    t_Node* newNode;

    newNode = malloc(sizeof(t_Node));
    if (!newNode) {
        return 0;
    }

    newNode->data = malloc(data_size);
    if (!newNode->data) {
        free(newNode);
        return 0;
    }

    memcpy(newNode->data, data, data_size);
    newNode->data_size = data_size;

    newNode->next = *stack;
    *stack = newNode;

    return 1;
}

int pop(t_Stack* stack, void* data, size_t data_size) {
    t_Node* eliminate = *stack;

    if (*stack == NULL) { // if stack is empty === if (!*stack)
        return 0;
    }

    // 2. memcpy
    memcpy(data, eliminate->data, MIN(eliminate->data_size, data_size));

    // 3. free(eliminate->data);
    free(eliminate->data);

    // 4. Assign previous node of current
    *stack = eliminate->next;
    free(eliminate);

    return 1;
}

int top(t_Stack* stack, void* data, size_t data_size) {
    if(!*stack) {
        return 0;
    }

    memcpy(data, (*stack)->data, MIN((*stack)->data_size, data_size)); /// (*stack)->data === **stack.data
    return 1;
}

int isEmpty(t_Stack* stack) {
    return *stack == NULL;
}

int isFull(t_Stack* stack, size_t data_size) {
    t_Node* test = malloc(sizeof(t_Node));

    if(!test) {
        return 1;
    }

    test->data = malloc(sizeof(data_size));
    if (!test->data) {
        free(test);
        return 1;
    }

    free(test->data);
    free(test);

    return 0;
}

void emptyStack(t_Stack* stack) {
    t_Node* eliminate = *stack;

    while(*stack) {
        eliminate = *stack;
        *stack = eliminate->next;

        free(eliminate->data);
        free(eliminate);
    }
}
