#include "library.h"

template <typename T> class Element2 {
public:
    T value;
    Element2* next;
    Element2() : value(), next(nullptr) {}
    Element2(T value) : value(value), next(nullptr) {}
    ~Element2() = default;
};

template <typename T> class Queue {
private:
    Element2<T>* _head;
    Element2<T>* _tail;
    int _size;

public:
    Queue() : _head(nullptr), _tail(nullptr), _size(0) {}
    ~Queue() {
        Element2<T>* temp = _head;
        while (temp != nullptr) {
            temp = temp->next;
            delete _head;
            _head = temp;
        }
        _tail = nullptr;
    }

    void push_back(T value) {
        Element2<T>* temp = new Element2<T>(value);
        if (_head == nullptr) {
            _head = temp;
            _tail = temp;
        }
        else {
            _tail->next = temp;
            _tail = temp;
        }
        _size++;
    }
    void push_front(T value) {
        Element2<T>* temp = new Element2<T>(value);
        if (_head == nullptr) {
            _head = temp;
            _tail = temp;
        }
        else {
            temp->next = _head;
            _head = temp;
        }
        _size++;
    }
    void pop_back() {
        if (_head == nullptr) {
            return;
        }
        else if (_head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
        }
        else {
            Element2<T>* temp = _head;
            while (temp->next != _tail) {
                temp = temp->next;
            }
            delete _tail;
            _tail = temp;
            _tail->next = nullptr;
        }
        _size--;
    }
    void pop_front() {
        if (_head == nullptr) {
            return;
        }
        else if (_head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
        }
        else {
            Element2<T>* temp = _head;
            _head = _head->next;
            delete temp;
        }
        _size--;
    }
    void print() {
        Element2<T>* temp = _head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void dev_print() {
        int index = 0;
        Element2<T>* temp = _head;
        while (temp != nullptr) {
            cout << "Element[" << index << "]: " << (long long)temp << endl;
            cout << "Value: " << temp->value << endl;
            cout << "Next element: " << (long long)temp->next << endl << endl;
            temp = temp->next;
            index++;
        }
        cout << endl;
    }
    int size() { return _size; }
};