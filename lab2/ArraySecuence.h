#ifndef LAB2_ARRAYSECUENCE_H
#define LAB2_ARRAYSECUENCE_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Secuence.h"

#include <iostream>

template <class T> class ArraySecuence : public Secuence<T>{
private:
    DynamicArray<T> array;
public:
    ArraySecuence() = default;
    explicit ArraySecuence(const DynamicArray<T> & arr) {
        array = DynamicArray<T>(arr);
    }
    ArraySecuence(T* arr, int quantity) {
        array.lenChange(quantity);
        for (int i = 0; i < quantity; i++) {
            array.addElement(arr[i]);
        }
    }
    ~ArraySecuence() {
        delete array;
    }
    virtual T GetFirst() override {
        return array[0];
    }
    virtual T GetLast() override {
        return array[array.getLen() - 1];
    }
    virtual T GetIndex(int index) override {
        return array[index];
    }
    virtual Secuence<T> GetSubSecuence(int startindex, int endindex) {
        Secuence<T> res;
        for (int i = startindex; i <= endindex; i++) {
            res.Append(array[i]);
        }
        return res;
    }
    virtual int GetLength() const override {
        return array.getLen();
    }
    virtual void Append(const & T item) {
        array.addElement(array.getLen(), item);
    }
    virtual void Prepend(const & T item) {
        for (int i = array .getLen(); i > 0; i--) {
            array.addElement(i, array[i-1]);
        }
        array.addElement(0, item);
    }
    virtual void InsertAt(const T & item, int index) {
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
    virtual ArraySecuence<T> operator+(const ArraySecuence<T> & arr1) {
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


#endif //LAB2_ARRAYSECUENCE_H
