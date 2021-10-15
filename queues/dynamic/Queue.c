#include "Queue.h"

void createQueue(t_Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
}

/*int push(t_Queue* queue, const void* data, size_t data_size);*/
/*int pop(t_Queue* queue, void* data, size_t data_size);*/
/*int front(const t_Queue* queue, void* data, size_t data_size);*/

int isEmpty(const t_Queue* queue) {
	return queue->front == NULL;
}

int isFull(const t_Queue* queue, size_t data_size) {
	t_Node* testNode = malloc(sizeof(t_Node));
	if( !testNode ) {
		return 1;
	}

	testNode->info = malloc(sizeof(data_size));
	if( !testNode->info ) {
		free(testNode);
		return 1;
	}

	free(testNode->info);
	free(testNode);

	return 0;
}

/*void emptyQueue(t_Queue* queue);*/
