#include <iostream>
#include "stack.hpp"

//build stack with array
struct stack{
    int top;
    int capacity;
    int* data;
};

stack* stack_init(int size){
    if(size < 1){
        std::cout << "the size is invalid" << std::endl;
        exit(1);
    }
    stack* st = new stack;
    st -> top = -1;
    st -> capacity = size - 1;
    st -> data = (int*)malloc(sizeof(int)*size);
    return st;
}

bool isFull(stack* st){
    return (st -> top == st -> capacity);
}

bool isEmpty(stack* st){
    return (st -> top == -1);
}

void push(stack* st, int x){
    if(isFull(st)){
        std::cout << "the stack is full" << std::endl;
        return;
    }
    st -> data[++st -> top] = x;
}

int pop(stack* st){
    if(isEmpty(st)){
        std::cout << "the stack is empty" << std::endl;
        exit(1);
    }
    return st -> data[st -> top--];
}

int peep(stack* st){
    if(isEmpty(st)){
        std::cout << "the stack is empty" << std::endl;
        exit(1);
    }
    return st -> data[st -> top];
}

void stack_free(stack* st){
    delete[] st -> data;
    delete st;
}

