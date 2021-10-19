#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Queue.h"

#define MIN(x, y) ( (x) < (y) ? (x) : (y) )

void createQueue(t_Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
}

int push(t_Queue* queue, const void* data, size_t data_size) {
	t_Node* newNode = malloc(sizeof(t_Node));
	if( !newNode ) {
		return 0;
	}

	newNode->info = malloc(data_size);
	if( !newNode->info ) {
		free(newNode);
		return 0;
	}

	newNode->next = NULL;
	newNode->info_size = data_size;
	memcpy(newNode->info, data, data_size);

	if( !(queue->front) ) {
		queue->front = newNode;
	} else {
		queue->rear->next = newNode;
	}

	queue->rear = newNode;

	return 1;
}

int pop(t_Queue* queue, void* data, size_t data_size) {
	t_Node* eliminate = queue->front;

	if( !eliminate ) {
		return 0;
	}

	memcpy(data, eliminate->info, MIN(eliminate->info_size, data_size));
	free(eliminate->info);

	queue->front = eliminate->next;
	free(eliminate);

	if( !queue->front ) {
		queue->rear = NULL;
	}

	return 1;
}

int front(const t_Queue* queue, void* data, size_t data_size) {
	if( !queue->front ) {
		return 0;
	}

	memcpy(data, queue->front->info, MIN(queue->front->info_size, data_size));

	return 1;
}

int isEmpty(const t_Queue* queue) {
	return queue->front == NULL;
}

int isFull(const t_Queue* queue, size_t data_size) {
	t_Node* testNode = malloc(sizeof(t_Node));
	if( !testNode ) {
		return 1;
	}

	testNode->info = malloc(data_size);
	if( !testNode->info ) {
		free(testNode);
		return 1;
	}

	free(testNode->info);
	free(testNode);

	return 0;
}

void emptyQueue(t_Queue* queue) {
	t_Node* eliminate;

	while(queue->front) {
		eliminate = queue->front;
		queue->front = eliminate->next;

		free(eliminate->info);
		free(eliminate);
	}

	queue->rear = NULL;
}
