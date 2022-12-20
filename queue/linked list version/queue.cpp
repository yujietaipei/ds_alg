#include <iostream>
#include "queue.hpp"

struct node{
    int val;
    struct node* next;
};

struct queue{
    int count;
    node* front;
    node* rear;
};

queue* init_queue(){
    queue* q = (queue*)malloc(sizeof(queue));
    q -> count = 0;
    q -> front = nullptr;
    q -> rear = nullptr;
    return q;
}

bool isEmpty(queue* q){
    return (q -> rear == nullptr);
}

void enqueue(queue* q, int data){
    node* tmp = (node*)malloc(sizeof(node));
    tmp -> val = data;
    tmp -> next = nullptr;
    q -> count++;
    if(q -> rear == nullptr){
        q -> rear = q -> front = tmp;
    }
    else{
        q -> rear -> next = tmp;
        q -> rear = tmp;
    }
}

int dequeue(queue* q){
    if(isEmpty(q)){
        std::cout << "the queue is empty" << std::endl;
        exit(1);
    }
    node* out = q -> front;
    int ans = q -> front -> val;
    q -> front = out -> next;
    q -> count--;
    delete out;
    out = nullptr;

    if(q -> front == nullptr){
        q -> rear = nullptr;
    }
    return ans;
}

void free_queue(queue* q){
    node* curr = q -> front;
    node* next;
    while(curr){
        next = curr -> next;
        delete curr;
        curr = next;
    }
    delete q;
    q = nullptr;
}



