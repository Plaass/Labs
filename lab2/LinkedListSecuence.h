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
    LinkedListSecuence(T* arr, int quantity) {
        list = LinkedList<T>(arr, quantity);
    }
    ~LinkedListSecuence() {
        delete list;
    }
    T & GetFirst() override {
        return list.GetFirst();
    };

   T & GetLast() override {
        return list.GetLast();
    }

    T & GetIndex(int index) override {
        return list.GetIndex(index);
    };

    Secuence<T>* GetSubSecuence(int startindex, int endindex) override {
        LinkedListSecuence<T>* sublist;
        for (int i = 0; i <= endindex - startindex; i++) {
            sublist->Append(list.GetIndex(i + startindex));
        }
        return sublist;
    };

    int GetLength() override{
        return list.GetLen();
    }

    void Append(const T & item) override{
        list.Append(item);
    }

    void Prepend(const T & item) override{
        list.Prepend(item);
    };

    void InsertAt(const T & item, int index) override{
        list.InsertAt(index, item);
    };

    LinkedListSecuence<T>*  Unite (Secuence<T>* arr1 = new LinkedListSecuence<T>(), Secuence<T>* arr2 = new LinkedListSecuence<T>()) override{
        // todo здесь есть ошибка
        //  что будет лежать в переменной sum после этой строчки?
        LinkedListSecuence<T>* sum;
        for (int i = 0; i < arr1->GetLength(); i++) {
            sum->Append(arr1->GetIndex(i));
        }
        for (int i = arr1->GetLength(); i < arr2->GetLength() + arr1->GetLength(); i++) {
            sum->Append(arr2->GetIndex(i - arr1->GetLength()));
        }
        return  sum;
    };
};


#endif //LAB2_LINKEDLISTSECUENCE_H
