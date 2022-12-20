#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include <iostream>

typedef struct node{
    int data;
    struct node* next;
    node():data(0),next(nullptr){};
    node(int input):data(input),next(nullptr){};
    node(int input, struct node* rear):data(input),next(rear){};
}node;

typedef struct list{
    node* head;
    node* tail;
}list;

list* newlist();
void insert_front(int, list*);
void insert_back(int, list*);
void delete_node(int, list*);
void reverse(list*);
node* middle(list*);
void print(list*);
bool empty(list*);
void free(list*);

#endif