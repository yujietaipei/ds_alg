#include <iostream>
#include "queue.hpp"

struct queue{
    int front;
    int back;
    int capacity;
    int* data;
};

queue* init_queue(int size){
    if(size < 1){
        std::cout << "the size is invalid" << std::endl;
        exit(1);
    }
    queue* q = (queue*)malloc(sizeof(queue));
    q -> back = 0;
    q -> front = 0;
    q -> data = (int*)malloc(sizeof(int)*(size+1)); //reserve a place for flag
    q -> capacity = size+1;
    return q;

}

bool isFull(queue* q){
    return ((q -> back + 1) % q -> capacity == q -> front);
}

bool isEmpty(queue* q){
    return (q -> back == q -> front);
}

void enqueue(queue* q, int x){
    if(isFull(q)){
        std::cout << "the queue is full";
        return;
    }
    q -> back = (q -> back + 1) % q -> capacity;
    q -> data[q -> back] = x;
}

int dequeue(queue* q){
    if(isEmpty(q)){
        std::cout << "the queue is empty" << std::endl;
        exit(1);
    }
    q -> front = (q -> front + 1) % q -> capacity;
    return q -> data[q -> front];
}

void free_queue(queue* q){
    delete[] q -> data;
    delete q;
    q = nullptr;
}

