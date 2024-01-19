#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstddef>
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
        size_t position = 0;
        while (current) {
            cout << "Position: " << position;
            cout << ", Data: " << current->data;
            if (current->prev) {
                cout << ", Prev: " << current->prev->data;
            }
            else {
                cout << ", Prev: nullptr";
            }
            if (current->next) {
                cout << ", Next: " << current->next->data;
            }
            else {
                cout << ", Next: nullptr";
            }
            cout << endl;
            current = current->next;
            ++position;
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

    void insertAtPosition(const T& value, size_t position) {
        if (position == 0) {
            addToHead(value);
        }
        else {
            Node* newNode = new Node(value);
            Node* current = head;
            size_t currentPosition = 0;

            while (current && currentPosition < position - 1) {
                current = current->next;
                currentPosition++;
            }

            if (current) {
                newNode->prev = current;
                newNode->next = current->next;

                if (current->next) {
                    current->next->prev = newNode;
                }
                else {
                    tail = newNode;
                }

                current->next = newNode;
            }
            else {
                addToTail(value);
            }
        }
    }

    void deleteAtPosition(size_t position) {
        Node* current = head;
        size_t currentPosition = 0;

        while (current && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }

        if (current) {
            if (current->prev) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }

            delete current;
        }
    }

    Node* findElement(const T& value) const {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    int replaceElement(const T& oldValue, const T& newValue) {
        int count = 0;
        Node* current = head;

        while (current) {
            if (current->data == oldValue) {
                current->data = newValue;
                count++;
            }
            current = current->next;
        }

        if (count > 0) {
            return count;
        }
        else {
            return -1;
        }
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
};

#endif