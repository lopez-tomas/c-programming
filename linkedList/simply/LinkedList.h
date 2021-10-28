#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct s_Node {
	void* info;
	size_t info_size;
	struct s_Node* next;
} t_Node;

typedef t_Node* t_LinkedList;

void createLinkedList(t_LinkedList* list);

#endif // LINKEDLIST_H
