#ifndef LAB2_LINKEDLISTSECUENCE_H
#define LAB2_LINKEDLISTSECUENCE_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Secuence.h"

#include <iostream>

template <class T> class LinkedListSecuence: public Secuence<T> {
private:
    LinkedList<T>* list;
public:
    LinkedListSecuence() = default;
    explicit LinkedListSecuence(const LinkedList<T> & arr) {
        list = arr;
    }
    LinkedListSecuence(T* arr, int quantity) {
        list = LinkedList<T>(arr, quantity);
    }
    ~LinkedListSecuence() {
        delete list;
    }
    T & GetFirst() override {
        return list->GetFirst();
    };

   T & GetLast() override {
        return list->GetLast();
    }

    T & GetIndex(int index) override {
        return list->GetIndex(index);
    };

    Secuence<T>* GetSubSecuence(int startindex, int endindex) override {
        LinkedListSecuence<T>* sublist;
        sublist -> list = list->GetSubList(startindex, endindex);
        return sublist;
    };

    int GetLength() override{
        return list->GetLen();
    }

    void Append(const T & item) override{
        list->Append(item);
    }

    void Prepend(const T & item) override{
        list->Prepend(item);
    };

    void InsertAt(const T & item, int index) override{
        list->InsertAt(index, item);
    };

    LinkedListSecuence<T>*  operator+(LinkedListSecuence<T>* arr1){
        LinkedListSecuence<T>* sum;
        sum->list = list + arr1 -> list;
        return  sum;
    };
};


#endif //LAB2_LINKEDLISTSECUENCE_H
