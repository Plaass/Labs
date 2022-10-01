#ifndef LAB2_ARRAYSECUENCE_H
#define LAB2_ARRAYSECUENCE_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Secuence.h"

#include <iostream>

template <class T> class ArraySecuence : public Secuence<T>{
private:
    DynamicArray<T>* array;
public:
    ArraySecuence() = default;
    explicit ArraySecuence(const DynamicArray<T> & arr) {
        array = DynamicArray<T>(arr);
    }
    ArraySecuence(T* arr, int quantity) {
        array->lenChange(quantity);
        for (int i = 0; i < quantity; i++) {
            array->addElement(arr[i]);
        }
    }
    ~ArraySecuence() {
        delete array;
    }
    T & GetFirst() override {
        return array[0];
    }
    T & GetLast() override {
        return array[array->getLen() - 1];
    }
    T & GetIndex(int index) override {
        return array[index];
    }
    Secuence<T>* GetSubSecuence(int startindex, int endindex) override {
        ArraySecuence<T>* res;
        for (int i = startindex; i <= endindex; i++) {
            res -> Append(array[i]);
        }
        return res;
    }
    int GetLength() override {
        return array->getLen();
    }
    void Append(const  T & item) override {
        array->addElement(array->getLen(), item);
    }
    void Prepend(const T & item) override {
        for (int i = array ->getLen(); i > 0; i--) {
            array->addElement(i, array[i-1]);
        }
        array->addElement(0, item);
    }
    void InsertAt(const T & item, int index) override {
        if (index < 0) {
            std::cout << "out of range" << std::endl;
        }
        else if (index > 1 && index < array->getLen() - 1) {
            for (int i = array->len; i > index; i--) {
                array->addElement(i, array[i - 1]);
            }
            array->addElement(index, item);
        }
        else if (index >= array -> len || index == 0 || index == array->len - 1) {
            array->addElement(index, item);
        }
    }
    ArraySecuence<T> * operator+(ArraySecuence<T> * arr1){
        ArraySecuence<T>* sumarr = ArraySecuence(array->getLen() + arr1->GetLength());
        for (int i = 0; i < array->len; i++) {
            sumarr[i] = array[i];
        }
        for (int i = array -> len; i < arr1->len; i++) {
            sumarr[i] = arr1[i - array->len];
        }
        return sumarr;
    }
};


#endif //LAB2_ARRAYSECUENCE_H
