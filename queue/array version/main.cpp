#include <iostream>
#include "queue.hpp"

using namespace std;

int main(void){
    //initialize a new queue
    queue* q = init_queue(2);
    cout << "the queue is empty ? " << isEmpty(q) << endl;

    //enqueue 10 and 3
    enqueue(q,10);
    enqueue(q,3);
    cout << "the queue is full ? " << isFull(q) << endl;
    cout << "the element " << dequeue(q) << " is discarded" << endl;
    free_queue(q);
    return 0;
}