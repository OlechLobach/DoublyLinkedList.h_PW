#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}

        const T& getData() const {
            return data;
        }

        Node* getNext() const {
            return next;
        }

        Node* getPrev() const {
            return prev;
        }

        void setNext(Node* nextNode) {
            next = nextNode;
        }

        void setPrev(Node* prevNode) {
            prev = prevNode;
        }
    };

    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (!rear) {
            front = rear = newNode;
        }
        else {
            newNode->setPrev(rear);
            rear->setNext(newNode);
            rear = newNode;
        }
    }

    void dequeue() {
        if (front) {
            Node* temp = front;
            front = front->getNext();
            if (front) {
                front->setPrev(nullptr);
            }
            else {
                rear = nullptr;
            }
            delete temp;
        }
    }

    const T& getFront() const {
        if (front) {
            return front->getData();
        }
        else {
            throw runtime_error("Queue is empty");
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void display() const {
        Node* current = front;
        while (current) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }

    ~Queue() {
        while (front) {
            Node* temp = front;
            front = front->getNext();
            delete temp;
        }
        rear = nullptr;
    }
};