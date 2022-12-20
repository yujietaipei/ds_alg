#include <iostream>
#include "stack.hpp"

using namespace std;

int main(void){
    //initialize a stack
    stack* st = stack_init(2);
    //push 4 and 3 onto the stack
    push(st,4);
    push(st,3);
    //the stack is full ? 1
    cout << "the stack is full ? " << isFull(st) << endl;
    //the top element is 3
    cout << "the top element is " << peep(st) << endl;
    //pop all elements on stack
    pop(st);
    pop(st);
    //the stack is empty? 1
    cout << "the stack is empty ? " << isEmpty(st) << endl;
    stack_free(st);
    return 0;
}