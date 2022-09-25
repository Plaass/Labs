#ifndef LAB2_SECUENCE_H
#define LAB2_SECUENCE_H

#include "DynamicArray.h"
#include "LinkedList.h"

#include <iostream>

template <class T> class Secuence {
public:
    virtual T GetFirst() = 0;

    virtual T GetLast() = 0;

    virtual T GetIndex(int index) = 0;

    virtual T *GetSubSecuence(int startindex, int endindex) = 0;

    virtual int GetLength() = 0;

    virtual void Append(T item) = 0;
};

template <class T> class ArraySecuence : public Secuence<T>{
private:
    DynamicArray<T> array;
public:
    ArraySecuence() = default;

    ArraySecuence(const DynamicArray<T> & arr) {
        array = DynamicArray<T>(arr);
    }
    ArraySecuence(T* arr, int quantity) {
//        arr = new DynamicArray<T>* [quantity];
        array.lenChange(quantity);
        for (int i = 0; i < quantity; i++) {
//            array[i] = arr[i];
            array.addElement(arr[i]);
        }
    }
    ~ArraySecuence() {
        delete [] array;
    }
    T & GetFirst() override {
        return array[0];
    }
    T & GetLast() override {
        return array[array.getLen() - 1];
    }
    T & GetIndex(int index) override {
        return array[index];
    }
    Secuence<T> GetSubSecuence(int startindex, int endindex) {
        Secuence<T> res;
//        T* arr = new T [endindex - startindex + 1];
        for (int i = startindex; i <= endindex; i++) {
//            arr[i - startindex] = array[i];
            res.Append(array[i]);
        }
//        return arr;
        return res;
    }
    int GetLength() const override {
        return array.getLen();
    }
    void Append(T item) {
        array.addElement(array.getLen(), item);
    }
    void Prepend(T item) {
        for (int i = array .getLen(); i > 0; i--) {
            array.addElement(i, array[i-1]);
        }
        array.addElement(0, item);
    }
    void InsertAt(T item, int index) {
        if (index < 0) {
            std::cout << "out of range" << std::endl;
        }
        else if (index > 1 && index < array .getLen() - 1) {
            for (int i = array . len; i > index; i--) {
                array.addElement(i, array[i - 1]);
            }
            array.addElement(index, item);
        }
        else if (index >= array -> len || index == 0 || index == array . len - 1) {
            array.addElement(index, item);
        }
    }
    ArraySecuence<T> operator+(const ArraySecuence<T> & arr1) {
        ArraySecuence<T> sumarr = ArraySecuence(array .getLen() + arr1.len);
        for (int i = 0; i < array . len; i++) {
            sumarr[i] = array[i];
        }
        for (int i = array -> len; i < arr1.len; i++) {
            sumarr[i] = arr1[i - array . len];
        }
        return sumarr;
    }
};

template <class T> class LinkedListSecuence: public Secuence<T> {
private:
    LinkedList<T>* array;
public:
    LinkedListSecuence() {
        array = new LinkedList<T>*;
    };
    LinkedListSecuence(const LinkedList<T> & arr) {
        array = LinkedList<T>(arr);
    }
    LinkedListSecuence(T* arr, int quantity) {
        arr -> LinkedList();
        for (int i = 0; i < quantity; i++) {
            array -> Append(arr[i]);
        }
    }
    ~LinkedListSecuence() {
        delete [] array;
    }
    T & GetFirst() {
        return array[0];
    }
    T & GetLast() {
        return array[array -> len - 1];
    }
    T GetIndex(int index) {
        return array[index];
    }
    T* GetSubSecuence(int startindex, int endindex) {
        T* arr = new T [endindex - startindex + 1];
        for (int i = startindex; i <= endindex; i++) {
            arr[i - startindex] = array[i];
        }
        return arr;
    }
    int GetLength() {
        return array -> len;
    }
    void Append(T item) {
        array->Append(item);
    }
    void Prepend(T item) {
        array->Prepend(item);
    }
    void InsertAt(T item, int index) {
        array->InsertAt(item, index);
    }
    LinkedListSecuence<T>* operator+(LinkedListSecuence<T>* arr1) {
        ArraySecuence<T>* sumarr = new LinkedListSecuence(array -> len + arr1 -> len);
        sumarr -> array = array + arr1 -> array;
        return sumarr;
    }
};
#endif //LAB2_SECUENCE_H
