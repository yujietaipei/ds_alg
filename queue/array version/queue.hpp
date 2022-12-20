#ifndef QUEUE_HPP
#define QUEUE_HPP

typedef struct queue queue;

queue* init_queue(int size);
bool isFull(queue* q);
bool isEmpty(queue* q);
void enqueue(queue* q, int x);
int dequeue(queue* q);
void free_queue(queue* q);

#endif