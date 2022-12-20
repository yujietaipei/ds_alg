#include <iostream>
#include "stack.hpp"

struct node{
    int data;
    struct node* next;
};

struct stack{
    node* top;
};

stack* init_stack(){
    stack* st = (stack*)malloc(sizeof(stack));
    st -> top = nullptr;
    return st;
}

bool isEmpty(stack* st){
    return (st -> top == nullptr);
}

void push(stack* st, int x){
    node* tmp = (node*)malloc(sizeof(node));
    tmp -> data = x;
    tmp -> next = st -> top;
    st -> top = tmp;
}


int pop(stack* st){
    if(isEmpty(st)){
        std::cout << "the stack is empty" << std::endl;
        exit(1);
    }
    node* out = st -> top;
    int ans = out -> data;
    st -> top = out -> next;
    delete out;
    out = nullptr;
    return ans;
}

int peep(stack* st){
    if(isEmpty(st)){
        std::cout << "the stack is empty" << std::endl;
        exit(1);
    }
    return st -> top -> data;
}

void stack_free(stack* st){
    node* curr = st -> top;
    node* next;
    while(curr){
        next = curr -> next;
        delete curr;
        curr = next;
    }
    delete st;
}

