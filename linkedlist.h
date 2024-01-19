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
            cout << "Data: " << current->data;
            if (current->prev) {
                cout << ", Prev: " << current->prev;
            }
            else {
                cout << ", Prev: nullptr";
            }
            if (current->next) {
                cout << ", Next: " << current->next;
            }
            else {
                cout << ", Next: nullptr";
            }
            cout << endl;
            current = current->next;
        }
    }

    Node* getPrev(Node* node) const { return node ? node->prev : nullptr; }
    Node* getNext(Node* node) const { return node ? node->next : nullptr; }

    void setPrev(Node* node, Node* prev) {
        if (node) {
            node->prev = prev;
        }
    }

    void setNext(Node* node, Node* next) {
        if (node) {
            node->next = next;
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
        os << ", Prev: " << node.prev;
    }
    else {
        os << ", Prev: nullptr";
    }
    if (node.next) {
        os << ", Next: " << node.next;
    }
    else {
        os << ", Next: nullptr";
    }
    return os;
}

#endif 