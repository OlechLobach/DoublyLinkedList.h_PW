#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Array {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;
    int capacity;
    int grow;

public:
    Array(int initialCapacity = 10, int initialGrow = 1)
        : head(nullptr), tail(nullptr), size(0), capacity(initialCapacity), grow(initialGrow) {
        initialize();
    }

    ~Array() {
        clear();
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int newSize, int newGrow = 1) {
        if (newSize > capacity) {
            reserve(newSize + newGrow);
            grow = newGrow;
        }
        else {
            removeExcess();
        }
    }

    int GetUpperBound() const {
        return size - 1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
        reserve(size);
    }

    void RemoveAll() {
        clear();
        initialize();
    }

    T GetAt(int index) const {
        if (index >= 0 && index < size) {
            return getNode(index)->data;
        }

        throw out_of_range("Index out of bounds");
    }

    void SetAt(int index, const T& value) {
        if (index >= 0 && index < size) {
            getNode(index)->data = value;
        }
        else {
            throw out_of_range("Index out of bounds");
        }
    }

    T& operator[](int index) {
        if (index >= 0 && index < size) {
            return getNode(index)->data;
        }
        throw out_of_range("Index out of bounds");
    }

    void Add(const T& value) {
        if (size == capacity) {
            reserve(size + grow);
        }
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void Append(const Array& other) {
        for (int i = 0; i < other.size; i++) {
            Add(other.GetAt(i));
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            clear();
            Append(other);
        }
        return *this;
    }

    T* GetData() const {
        T* data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = GetAt(i);
        }
        return data;
    }

    void InsertAt(int index, const T& value) {
        if (index >= 0 && index <= size) {
            if (size == capacity) {
                reserve(size + grow);
            }
            Node* newNode = new Node(value);
            if (index == 0) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            else if (index == size) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else {
                Node* current = getNode(index);
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }
            size++;
        }
        else {
            throw out_of_range("Index out of bounds");
        }
    }

    void RemoveAt(int index) {
        if (index >= 0 && index < size) {
            Node* current = getNode(index);
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
            size--;
            removeExcess();
        }
        else {
            throw out_of_range("Index out of bounds");
        }
    }

    void PrintArray() const {
        cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            cout << GetAt(i) << " ";
        }
        cout << endl;
    }

private:
    void initialize() {
        head = tail = nullptr;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        initialize();
    }

    Node* getNode(int index) const {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    void reserve(int newCapacity) {
        if (newCapacity > capacity) {
            capacity = newCapacity;
        }
        else {
            return;
        }

        Node* current = head;
        head = tail = nullptr;
        while (current) {
            Node* next = current->next;
            if (tail == nullptr) {
                head = tail = new Node(current->data);
            }
            else {
                tail->next = new Node(current->data);
                tail->next->prev = tail;
                tail = tail->next;
            }
            delete current;
            current = next;
        }
        for (int i = size; i < capacity; i++) {
            Add(T());
        }
    }

    void removeExcess() {
        Node* current = getNode(size - 1)->next;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

#endif