#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_DIM 25

typedef struct {
    char queue[QUEUE_DIM];
    unsigned front;
    unsigned rear;
    unsigned available;
} t_Queue;

void createQueue(t_Queue* queue);
int push(t_Queue* queue, const void* data, unsigned data_size);
int pop(t_Queue* queue, void* data, unsigned data_size);
int front(const t_Queue* queue, void* data, unsigned data_size);
int isEmpty(const t_Queue* queue);
int isFull(const t_Queue* queue, unsigned data_size);
void emptyQueue(t_Queue* queue);

#endif // QUEUE_H
