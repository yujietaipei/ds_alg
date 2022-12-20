#include <iostream>
#include "queue.hpp"

using namespace std;

int main(void){
    //initialize a queue
    queue* q = init_queue();

    enqueue(q,10);
    enqueue(q,20);

    cout << dequeue(q) << " is discarded" << endl;
    cout << dequeue(q) << " is discarded" << endl;
    cout << "the queue is empty ? " << isEmpty(q) << endl;
    free_queue(q);
    return 0;
}