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
    unsigned info_size,
             start,
             end;

    if( queue->available == QUEUE_DIM ) {
        return 0;
    }

    if( (start = MIN(sizeof(unsigned), QUEUE_DIM - queue->front)) != 0 ) {
            memcpy(&info_size, queue->queue + queue->front, start);
    }

    if( (end = sizeof(unsigned) - start) != 0 ) {
        memcpy(((char*)&info_size) + start, queue->queue, end);
    }

    queue->front = end ? end : queue->front + start;
    queue->available += sizeof(unsigned) + info_size;
    info_size = MIN(info_size, data_size);

    if( (start = MIN(info_size, QUEUE_DIM - queue->front)) != 0 ) {
        memcpy(data, queue->queue + queue->front, start);
    }

    if( (end = info_size - start) != 0 ) {
        memcpy(((char*)data) + start, queue->queue, end);
    }

    queue->front = end ? end : queue->front + start;

    return 1;
}

int front(const t_Queue* queue, void* data, unsigned data_size) {
    unsigned info_size,
             start,
             end,
             pos = queue->front;

    if(queue->available == QUEUE_DIM) {
        return 0;
    }

    if( (start = MIN(sizeof(unsigned), QUEUE_DIM - pos)) != 0 ) {
        memcpy(&info_size, queue->queue + pos, start);
    }

    if( (end = sizeof(unsigned) - start) != 0 ) {
        memcpy(((char*)&info_size) + start, queue->queue, end);
    }

    pos = end ? end : pos + start;
    info_size = MIN(info_size, data_size);

    if( (start = MIN(info_size, QUEUE_DIM - pos)) != 0 ) {
        memcpy(data, queue->queue + pos, start);
    }

    if( (end = info_size - start) != 0 ) {
        memcpy(((char*)data) + start, queue->queue, end);
    }

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
