#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <string>
typedef struct node node;

node** init_hashtable(int size);
unsigned long hash(std::string str);
void insert(node** table, std::string str);
bool lookup(node** table, std::string str);

#endif