#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct s_Node {
	void* info;
	size_t info_size;
	struct s_Node* next;
} t_Node;

#endif // LINKEDLIST_H
