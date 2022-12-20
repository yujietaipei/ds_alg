#ifndef STACK_HPP
#define STACK_HPP

typedef struct node node;
typedef struct stack stack;

stack* init_stack();
bool isEmpty(stack* st);
void push(stack* st, int x);
int pop(stack* st);
int peep(stack* st);
void stack_free(stack* st);

#endif