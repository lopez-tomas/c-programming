#ifndef STACK_H
#define STACK_H

#define STACK_DIM 100

typedef struct {
	char stack[STACK_DIM];
	unsigned top;
} t_Stack;

void createStack(t_Stack* stack);
int push(t_Stack* stack, const void* data, unsigned data_size);
int pop(t_Stack* stack, void* data, unsigned data_size);
int top(t_Stack* stack, void* data, unsigned data_size);
int isEmpty(const t_Stack* stack);
int isFull(const t_Stack* stack, unsigned data_size);
void emptyStack(t_Stack* stack);

#endif // STACK_H
