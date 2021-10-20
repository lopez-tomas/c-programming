#include "Queue.h"

void createQueue(t_Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->available = QUEUE_DIM;
}

int push(t_Queue* queue, const void* data, unsigned data_size) {
    return 1;
}

int pop(t_Queue* queue, void* data, unsigned data_size) {
    return 1;
}

int front(const t_Queue* queue, void* data, unsigned data_size) {
    return 1;
}

int isEmpty(const t_Queue* queue) {
    return queue->available == QUEUE_DIM;
}

int isFull(const t_Queue* queue, unsigned data_size) {
    return queue->available < (data_size + sizeof(unsigned));
}

void emptyQueue(t_Queue* queue) {
    queue->front = queue->rear;
    queue->available = QUEUE_DIM;
}
