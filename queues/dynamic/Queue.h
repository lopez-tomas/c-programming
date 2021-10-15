#ifndef QUEUE_H
#define QUEUE_H

#include "stdlib.h"

typedef struct s_Node {
	void* data;
	size_t data_size;
	struct s_Node* next;
} t_Node;

typedef struct {
	t_Node* front;
	t_Node* rear;
} t_Queue;

#endif // QUEUE_H
