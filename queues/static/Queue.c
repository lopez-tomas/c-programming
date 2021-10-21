#include "Queue.h"
#include <string.h>

#define MIN(x,y) ((x) < (y) ? (x) : (y))

void createQueue(t_Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->available = QUEUE_DIM;
}

int push(t_Queue* queue, const void* data, unsigned data_size) {
    unsigned start, end;

    if( queue->available < (data_size + sizeof(unsigned))) {
        return 0;
    }

    queue->available -= data_size + sizeof(unsigned);

    // For data_size
    start = MIN(sizeof(unsigned), QUEUE_DIM - queue->rear);
    memcpy(queue->queue + queue->rear, &data_size, start);

    end = sizeof(unsigned) - start;
    memcpy(queue->queue, ((char*)&data_size) + start, end);

    queue->rear = end ? end : queue->rear + start;

    // For data
    start = MIN(data_size, QUEUE_DIM - queue->rear);
    memcpy(queue->queue + queue->rear, data, start);

    end = data_size - start;
    memcpy(queue->queue, ((char*)data) + start, start);

    queue->rear = end ? end : queue->rear + start;

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
