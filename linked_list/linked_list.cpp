//linked list implementation
#include <iostream>
#include "linked_list.hpp"


//initialize a list
list* newlist(){
    list* newone = new list;
    newone -> head = new node(0);
    newone -> tail = newone -> head;
    return newone;
}

//insert
void insert_front(int data, list* linked){
    node* curr = new node(data);
    if(linked -> head == linked -> tail){
        linked -> head -> next = curr;
        linked -> tail = curr;
    }
    else{
        node* rear = linked -> head -> next;
        linked -> head -> next = curr;
        curr -> next = rear;
    }
}

void insert_back(int data, list* linked){
    node* curr = new node(data);
    linked -> tail -> next = curr;
    linked -> tail = curr;
}

//delete
void delete_node(int data, list* linked){
    node* curr = linked -> head -> next;   //skip fake node
    node* pre = linked -> head;
    while(curr){
        if(curr -> data == data){
            pre -> next = curr -> next;
            if(curr == linked -> tail){
                linked -> tail = pre;
            }
            delete curr;
            curr = nullptr;
            return;
        }
        pre = curr;
        curr = curr -> next;
    }
    std::cout << "the data is not found" << std::endl;
}

//reverse
void reverse(list* linked){
    if(!empty(linked)){
        node* pre = nullptr;
        node* curr = nullptr;
        node* rear = linked -> head -> next;
        while(rear){
            pre = curr;
            curr = rear;
            rear = rear -> next;
            curr -> next = pre;
        }
        linked -> tail = linked -> head -> next;
        linked -> head -> next = curr;
    }
    else{
        std::cout << "the list is empty" << std::endl;
    }

    
}

//find the middle 
node* middle(list* linked){
    if(!empty(linked)){
        //skip fake head
        node* tortoise = linked -> head -> next;
        node* hare = linked -> head -> next;
        while(hare && hare -> next){
            tortoise = tortoise -> next;
            hare = hare -> next -> next;
        }
        return tortoise;
    }
    else{
        std::cout << "the list is empty";
        return nullptr;
    }

}

//print
void print(list* linked){
    if(!empty(linked)){
        node*curr = linked -> head -> next;
        while(curr != linked -> tail){
            std::cout << curr -> data << " ->> ";
            curr = curr -> next;
        }
        std::cout << curr -> data << std::endl;
    }
}

bool empty(list* linked){
    return linked -> head == linked -> tail;
}

//free
void free(list* linked){
    node* pre = linked -> head;
    node* curr = linked -> head -> next;
    while(curr){
        delete pre;
        pre = curr;
        curr = curr -> next;
    }
    delete pre;

    delete linked;
}