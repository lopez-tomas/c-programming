#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct s_Node {
	void* data;
	size_t data_size;
	struct s_Node* next;
} t_Node;

typedef t_Node* t_Stack;

void createStack(t_Stack* stack);
int push(t_Stack* stack, const void* data, size_t data_size);
int pop(t_Stack* stack, void* data, size_t data_size);
int top(t_Stack* stack, void* data, size_t data_size);
int isEmpty(t_Stack* stack);
int isFull(t_Stack* stack, size_t data_size);
void emptyStack(t_Stack* stack);

#endif // STACK_H
