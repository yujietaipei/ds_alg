#include "linked_list.hpp"
#include <iostream>
using namespace std;

int main(){
    //initialize a list
    list* alist = newlist();

    insert_front(3,alist);
    insert_front(5,alist);
    insert_back(9,alist);
    // 5 ->> 3 ->> 9
    print(alist);
    // the middle node is 3
    cout << "the middle node is " << middle(alist) -> data << std::endl;
    delete_node(5,alist);
    // 3 ->> 9
    print(alist);
    // reverse the linked list
    reverse(alist);
    // 9 ->> 3
    print(alist);
    //free all allocated memory
    free(alist);
    return 0;
}