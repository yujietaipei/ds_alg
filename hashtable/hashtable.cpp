#include <iostream>
#include <vector>
#include <string>
#include "hashtable.hpp"
#define TABLE_SIZE 100

struct node{
    std::string data;
    struct node* next;
};

node** init_hashtable(int size){
     node** table = new node* [TABLE_SIZE];
     for(int i = 0;i < TABLE_SIZE;i++){
        table[i] = nullptr;
     }
     return table;
}

//hash function
unsigned long hash(std::string str){
    unsigned long key = 0;
    for(int i = 0;i < str.length();i++){
        key = key * 26 + (str[i] - '0');
    }
    return key % TABLE_SIZE;
}

//insert
void insert(node** table, std::string str){
    unsigned long key = hash(str);
    if(lookup(table, str)){
        return;
    }
    node* newone = new node;
    newone -> data = str;
    newone -> next = table[key];
    table[key] = newone;
    
}

bool lookup(node** table, std::string str){
    unsigned long key = hash(str);
    node* curr = table[key];
    while(curr){
        if(curr -> data.compare(str) == 0){
            //the string exists in hashtable
            return 1;
        }
        curr = curr -> next;
    }
    return 0;
}




