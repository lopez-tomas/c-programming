#include <string.h>
#include "Stack.h"

#define MIN(x, y) ( (x) < (y) ? (x) : (y) )

void createStack(t_Stack* stack) {
    stack->top = STACK_DIM;
}

int push(t_Stack* stack, const void* data, unsigned data_size) {
    if( stack->top < (data_size + sizeof(stack->top)) ) {
        return 0;
    }

    stack->top -= data_size;
    memcpy(stack->stack + stack->top, data, data_size);

    stack->top -= sizeof(stack->top);
    memcpy(stack->stack + stack->top, &data_size, sizeof(unsigned));
    /**((unsigned*)(stack->stack + stack->top)) = data_size;*/

    return 1;
}

int pop(t_Stack* stack, void* data, unsigned data_size) {
    unsigned dim;

    if(stack->top == STACK_DIM) {
        return 0;
    }

    memcpy(&dim, stack->stack + stack->top, sizeof(unsigned));
    stack->top += sizeof(stack->top);

    memcpy(data, stack->stack + stack->top, MIN(data_size, dim));
    stack->top += dim;

    return 1;
}

int top(t_Stack* stack, void* data, unsigned data_size) {
    unsigned dim;

    if(stack->top == STACK_DIM) {
        return 0;
    }

    memcpy(&dim, stack->stack + stack->top, sizeof(unsigned));
    memcpy(data, (stack->stack + stack->top) + sizeof(stack->top), MIN(data_size, dim));

    return 1;
}

int isEmpty(const t_Stack* stack) {
    return stack->top == STACK_DIM;
}

int isFull(const t_Stack* stack, unsigned data_size) {
    return ( stack->top < (data_size + sizeof(unsigned)) );
}

void emptyStack(t_Stack* stack) {
    stack->top = STACK_DIM;
}
