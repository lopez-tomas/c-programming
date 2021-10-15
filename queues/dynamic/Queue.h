#ifndef QUEUE_H
#define QUEUE_H

#include "stdlib.h"

typedef struct s_Node {
	void* info;
	size_t info_size;
	struct s_Node* next;
} t_Node;

typedef struct {
	t_Node* front;
	t_Node* rear;
} t_Queue;

void createQueue(t_Queue* queue);
int push(t_Queue* queue, const void* data, size_t data_size);
int pop(t_Queue* queue, void* data, size_t data_size);
int front(const t_Queue* queue, void* data, size_t data_size);
int isEmpty(const t_Queue* queue);
int isFull(const t_Queue* queue, size_t data_size);
void emptyQueue(t_Queue* queue);

#endif // QUEUE_H
