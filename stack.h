#include "library.h"

//template <typename T> class Element {
//public:
//    T value;
//    Element* next;
//    Element() : value(), next(nullptr) {}
//    Element(T value) : value(value), next(nullptr) {}
//    ~Element() = default;
//};
//
//template <typename T> class stack {
//private:
//   // Element<T>* _head;
//    Element<T>* _tail;
//    int _size;
//
//public:
//    stack() : _tail(nullptr), _size(0) {}
//    ~stack() {
//        /*while (!isEmpty()) {*/
//            //push_back();
//        //}
//        /*Element<T>* temp = _head;
//        while (temp != nullptr) {
//            temp = temp->next;
//            delete _head;
//            _head = temp;
//        }
//        _tail = nullptr;*/
//    }
//
//    void push_back(T value) 
//    {
//        /*if (isFull()) 
//        {
//            extend_memmory();
//        }*/
//        Element<T>* temp = new Element<T>(value);
//        _tail->next = temp;
//        _tail = temp;
//
//        _size++;
//    }
//    void pop_back() 
//    {
//      /*  if (isEmpty()) 
//        {
//            return 0;
//        }*/
//       
//           /* while (temp->next != _tail) 
//            {
//                temp = temp->next;
//            }
//            delete _tail;
//            _tail = temp;
//            _tail->next = nullptr;*/
//            Element<T>* temp = _tail;
//            _tail = _tail->next;
//        
//       // _size--;
//    }
//    T top()
//    {
//        /*if (isEmpty())
//            cout << "error";*/
//
//		return _tail->value;
//    }
//    //void print() {
//    //    Element<T>* temp = _head;
//    //    while (temp != nullptr) {
//    //        cout << temp->value << " ";
//    //        temp = temp->next;
//    //    }
//    //    cout << endl;
//    //}
//    //void dev_print() {
//    //    int index = 0;
//    //    Element<T>* temp = _head;
//    //    while (temp != nullptr) {
//    //        cout << "Element[" << index << "]: " << (long long)temp << endl;
//    //        cout << "Value: " << temp->value << endl;
//    //        cout << "Next element: " << (long long)temp->next << endl << endl;
//    //        temp = temp->next;
//    //        index++;
//    //    }
//    //    cout << endl;
//    //}
//    int size() { return _size; }
//};

template <typename T> class Element {
public:
    T value;
    Element* next;
    Element() : value(), next(nullptr) {}
    Element(T value) : value(value), next(nullptr) {}
    ~Element() = default;
};

template <typename T> class stack {
private:
    Element<T>* _head;
    Element<T>* _tail;
    int _size;

public:
    stack() : _head(nullptr), _tail(nullptr), _size(0) {}
    ~stack() {
        Element<T>* temp = _head;
        while (temp != nullptr) {
            temp = temp->next;
            delete _head;
            _head = temp;
        }
        _tail = nullptr;
    }

    void push_back(T value) {
        Element<T>* temp = new Element<T>(value);
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
            Element<T>* temp = _head;
            while (temp->next != _tail) {
                temp = temp->next;
            }
            delete _tail;
            _tail = temp;
            _tail->next = nullptr;
        }
        _size--;
    }
    void print() {
        Element<T>* temp = _head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void dev_print() {
        int index = 0;
        Element<T>* temp = _head;
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