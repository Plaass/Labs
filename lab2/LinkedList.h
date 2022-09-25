
#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H

#include <iostream>

template <class T> class LinkedList {
private:
    LinkedList<T>* next;
    LinkedList<T>* start;
    T element;
    int len;
public:
    LinkedList(): start(nullptr), next(nullptr), element(nullptr), len(0) {};
    explicit LinkedList(int len): element(nullptr), len(len) {
        start = new LinkedList();
        next = start;
        for (int i = 0; i < len; i++) {
            next -> next = new LinkedList();
            next = next -> next;
        }
        next = start;
    };
    LinkedList(const LinkedList<T> & array) {
        start = new LinkedList(array -> len);
        next = start;
        for (int i = 0; i < start -> len; i++) {
            next -> element = array . element;
            next = next -> next;
        }
        next = start;
    }
    LinkedList & operator=(const LinkedList<T> & array) {
        delete start;
        delete next;
        delete element;
        start = new LinkedList(array -> len);
        next = start;
        for (int i = 0; i < start -> len; i++) {
            next -> element = array . element;
            next = next -> next;
        }
        next = start;
        return *this;
    }
    ~LinkedList() {
        delete start;
        delete next;
        delete element;
    };
    T GetFirst() {
        return start -> element;
    }
    T GetLast() {
        next = start;
        for (int i = 0; i < len; i++) {
            next = next -> next;
        }
        return next -> element;
    }
    T & operator[](int index) {
        next = start;
        if (index < 0) {
            std::cout << "wrong_index" << std::endl;;
            return nullptr;
        }
        else if (index > len - 1) {
            std::cout << "too_far_away..." << std::endl;;
            return nullptr;
        }
        else for (int i = 0; i <= index; i++) {
            next = next -> next;
        }
        return next -> element;
    };
    LinkedList<T>* GetSubList(int startIndex, int endIndex) {
        if ((0 <= startIndex) && (startIndex <= endIndex) && (endIndex < len)) {
            next = start;
            LinkedList<T>* array = new LinkedList(endIndex - startIndex + 1);
            for (int i = 0; i <= endIndex; i++) {
                next = next -> next;
                if (i >= startIndex) {
                    array -> next -> element = next -> element;
                    array -> next = array -> next -> next;
                }
            }
            array -> next = array -> start;
            next = start;
            return array;
        }
        else {
            std::cout << "wrong indexes" << std::endl;
            return nullptr;
        }
    }
    int GetLength() {
        return len;
    };
    void Append(T item) {
        next = start;
        for (int i = 0; i < len; i++) {
            next = next -> next;
        }
        next -> next = new LinkedList();
        next -> next -> element = item;
        next = start;
    }
    void Prepend(T item) {
        next = start;
        start = new LinkedList();
        start -> element = item;
        start -> next = next;
        next = start;
    }
    void InsertAt(T item, int index) {
        if (index > 0 && index < len) {
            next = start;
            for (int i = 0; i < index; i++) next = next->next;
            LinkedList<T> *tmp = new LinkedList();
            tmp->element = item;
            tmp->next = next->next;
            next->next = tmp;
        }
        else {
            std::cout << "OutOfRange" << std::endl;
        }
    }
    LinkedList<T>* operator+(LinkedList<T>* arr1) {
        LinkedList<T>* L = new LinkedList(len + arr1 -> len);
        next = start;
        for (int i = 0; i < arr1 -> len; i++) {
            L -> next -> element = arr1 -> next -> element;
            L -> next = L -> next -> next;
            arr1 -> next = arr1 -> next -> next;
        }
        for (int i = arr1 -> len; i < arr1 -> len + len; i++) {
            L -> next -> element = next -> element;
            L -> next = L -> next -> next;
            next = next -> next;
        }
        L -> next = L -> start;
        arr1 -> next = arr1 -> start;
        next = start;
        return L;
    }
};


#endif //LAB2_LINKEDLIST_H
