#include"linkedlist.h"


int main() {
    DoublyLinkedList<int> myList;

    myList.addToHead(3);
    myList.addToHead(2);
    myList.addToHead(1);

    myList.show(); 

    myList.addToTail(4);
    myList.addToTail(5);

    myList.show(); 

    myList.deleteFromHead();
    myList.deleteFromTail();

    myList.show(); 

    myList.deleteAll();

    myList.show(); 

    return 0;
}