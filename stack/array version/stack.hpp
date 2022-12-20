#ifndef STACK_HPP
#define STACK_HPP

typedef struct stack stack;

stack* stack_init(int);
bool isFull(stack*);
bool isEmpty(stack*);
void push(stack*,int);
int pop(stack*);
int peep(stack*);
void stack_free(stack*);

#endif