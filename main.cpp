#include"linkedlist.h"

int main() {
    Queue<int> myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Queue front: " << myQueue.getFront() << endl;

    myQueue.dequeue();
    myQueue.enqueue(40);

    cout << "Queue front after dequeue and enqueue: " << myQueue.getFront() << endl;

    cout << "Is Queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

    cout << "Queue elements: ";
    myQueue.display();

    return 0;
}