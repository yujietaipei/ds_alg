#include <iostream>
#include "stack.hpp"

using namespace std;

int main(void){
    
    //initialize a stack
    stack* st = init_stack();
    cout << "the stack is empty ? " << isEmpty(st) << endl;
    //push 9 and 10 onto the stack
    push(st, 9);
    push(st, 10);
    cout << "the top element is " << peep(st) << endl;
    cout << "the top element " << pop(st) << " is discarded" << endl;
    cout << "the top element " << pop(st) << " is discarded" << endl;

    stack_free(st);
    return 0;
}