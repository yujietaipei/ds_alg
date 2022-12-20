#ifndef QUEUE_HPP
#define QUEUE_HPP

typedef struct node node;
typedef struct queue queue;

queue* init_queue();
bool isEmpty(queue* q);
void enqueue(queue* q, int data);
int dequeue(queue* q);
void free_queue(queue* q);
#endif