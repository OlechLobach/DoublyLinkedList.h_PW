#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {
public:
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addToHead(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addToTail(const T& value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFromHead() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
        }
    }

    void deleteFromTail() {
        if (tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
            delete temp;
        }
    }

    void deleteAll() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void show() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    DoublyLinkedList<T>* cloneList() const {
        DoublyLinkedList<T>* clonedList = new DoublyLinkedList<T>();
        Node* current = head;

        while (current) {
            clonedList->addToTail(current->data);
            current = current->next;
        }

        return clonedList;
    }

    DoublyLinkedList<T>* operator+(const DoublyLinkedList<T>& otherList) const {
        DoublyLinkedList<T>* combinedList = new DoublyLinkedList<T>();

        Node* currentThis = head;
        while (currentThis) {
            combinedList->addToTail(currentThis->data);
            currentThis = currentThis->next;
        }

        Node* currentOther = otherList.head;
        while (currentOther) {
            combinedList->addToTail(currentOther->data);
            currentOther = currentOther->next;
        }

        return combinedList;
    }

    DoublyLinkedList<T>* operator*(const DoublyLinkedList<T>& otherList) const {
        DoublyLinkedList<T>* commonElementsList = new DoublyLinkedList<T>();

        Node* currentThis = head;
        while (currentThis) {
            Node* currentOther = otherList.head;
            while (currentOther) {
                if (currentThis->data == currentOther->data) {
                    commonElementsList->addToTail(currentThis->data);
                    break;
                }
                currentOther = currentOther->next;
            }
            currentThis = currentThis->next;
        }

        return commonElementsList;
    }

    void reverseList() {
        Node* current = head;
        Node* temp = nullptr;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp) {
            head = temp->prev;
        }
    }

    ~DoublyLinkedList() {
        deleteAll();
    }
};

template <typename T>
ostream& operator<<(ostream& os, const typename DoublyLinkedList<T>::Node& node) {
    os << "Data: " << node.data;
    if (node.prev) {
        os << ", Prev: " << node.prev->data;
    }
    else {
        os << ", Prev: nullptr";
    }
    if (node.next) {
        os << ", Next: " << node.next->data;
    }
    else {
        os << ", Next: nullptr";
    }
    return os;
}


char displayMenu() {
    cout << "Menu:\n";
    cout << "1. Clone List\n";
    cout << "2. Combine Lists\n";
    cout << "3. Find Common Elements\n";
    cout << "4. Reverse List\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";

    char choice;
    cin >> choice;
    return choice;
}

template <typename T>
void performOperation(DoublyLinkedList<T>& originalList, char operation) {
    cout << "Original List: ";
    originalList.show();

    switch (operation) {
    case '1': {

        DoublyLinkedList<T>* clonedList = originalList.cloneList();
        cout << "Cloned List: ";
        clonedList->show();
        delete clonedList;
        break;
    }
    case '2': {

        DoublyLinkedList<T> otherList;
        otherList.addToTail(4);
        otherList.addToTail(5);

        cout << "Other List: ";
        otherList.show();

        DoublyLinkedList<T>* combinedList = originalList + otherList;
        cout << "Combined List: ";
        combinedList->show();
        delete combinedList;
        break;
    }
    case '3': {

        DoublyLinkedList<T> otherList;
        otherList.addToTail(2);
        otherList.addToTail(3);
        otherList.addToTail(4);

        cout << "Other List: ";
        otherList.show();

        DoublyLinkedList<T>* commonElementsList = originalList * otherList;
        cout << "Common Elements List: ";
        commonElementsList->show();
        delete commonElementsList;
        break;
    }
    case '4':

        originalList.reverseList();
        cout << "Reversed List: ";
        originalList.show();
        break;
    case '5':

        cout << "Exiting...\n";
        break;
    default:
        cout << "Invalid choice\n";
    }

    cout << "Modified List: ";
    originalList.show();
    cout << "------------------------------------\n";
}

#endif 