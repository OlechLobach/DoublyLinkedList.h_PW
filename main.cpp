#include"linkedlist.h"
int main() {
    DoublyLinkedList<int> myList1;
    myList1.addToHead(3);
    myList1.addToHead(2);
    myList1.addToHead(1);

    char userChoice;
    do {
        userChoice = displayMenu();
        performOperation(myList1, userChoice);

    } while (userChoice != '5');

    return 0;
}