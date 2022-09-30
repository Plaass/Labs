#ifndef LAB2_LINKEDLISTSECUENCE_H
#define LAB2_LINKEDLISTSECUENCE_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Secuence.h"

#include <iostream>

template <class T> class LinkedListSecuence: public Secuence<T> {
private:
    LinkedList<T> list;
public:
    LinkedListSecuence() = default;
    explicit LinkedListSecuence(const LinkedList<T> & arr) {
        list = arr;
    }
    LinkedListSecuence(T* & arr, const int & quantity) {
        list = LinkedList<T>(arr, quantity);
    }
    ~LinkedListSecuence() {
        delete list;
    }
    T GetFirst() override {
        return list.GetFirst();
    };

    virtual T GetLast() {
        return list.GetLast();
    }

    virtual T GetIndex(int index) {
        return list.GetIndex(index);
    };

    virtual T *GetSubSecuence(int startindex, int endindex) {
        return list.GetSubList(startindex, endindex);
    };

    virtual int GetLength() {
        return list.GetLen();
    }

    virtual void Append(T item) {
        list.Append(item);
    }

    virtual void Prepend(T item) {
        list.Prepend(item);
    };

    virtual void InsertAt(T item, int & index) {
        list.InsertAt(index, item);
    };

    LinkedListSecuence<T> operator+(const LinkedListSecuence<T> & arr1) {
        return list + arr1.list;
    };
};


#endif //LAB2_LINKEDLISTSECUENCE_H
