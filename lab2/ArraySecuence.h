#ifndef LAB2_ARRAYSECUENCE_H
#define LAB2_ARRAYSECUENCE_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Secuence.h"

#include <sstream>
#include <iostream>

template <class T> class ArraySecuence : public Secuence<T>{
private:
    DynamicArray<T> array;
public:
    ArraySecuence() = default;
    explicit ArraySecuence(const DynamicArray<T> & arr) {
        array = DynamicArray<T>(arr);
    }
    explicit ArraySecuence(int len) {
        array = DynamicArray<T>(len);
    }
    ArraySecuence(T* arr, int quantity) {
        array->lenChange(quantity);
        for (int i = 0; i < quantity; i++) {
            array->addElement(arr[i]);
        }
    }
    std::string ToString() override {
        std::ostringstream str;
        str << "{ ";
        for (int i = 0; i < this->GetLength(); i++) {
            str << this->GetIndex(i) << " ";
        }
        str << "}";
        return str.str();
    }
    T & GetFirst() override {
        return array.at(0);
    }
    T & GetLast() override {
        return array.at(array.getLen() - 1);
    }
    T & GetIndex(int index) override {
        return array.at(index);
    }
    Secuence<T>* GetSubSecuence(int startindex, int endindex) override {
        // todo здесь есть ошибка
        //  что будет лежать в переменной sum после этой строчки?
        ArraySecuence<T>* res = new ArraySecuence<T>();
        for (int i = startindex; i <= endindex; i++) {
            res -> Append(array.at(i));
        }
        return res;
    }
    int GetLength() override {
        return array.getLen();
    }
    void Append(const  T & item) override {
        array.addElement(array.getLen(), item);
    }
    void Prepend(const T & item) override {
        for (int i = array.getLen(); i > 0; i--) {
            array.addElement(i, array.at(i-1));
        }
        array.addElement(0, item);
    }
    void InsertAt(const T & item, int index) override {
        if (index < 0) {
            std::cout << "out of range" << std::endl;
        }
        else if (index > 1 && index < array.getLen() - 1) {
            for (int i = array.getLen(); i > index; i--) {
                array.addElement(i, array.at(i-1));
            }
            array.addElement(index, item);
        }
        else if (index >= array . getLen() || index == 0 || index == array.getLen() - 1) {
            array.addElement(index, item);
        }
    }
    ArraySecuence<T> * Unite(Secuence<T> * arr1 = new ArraySecuence<T>()) override{
        ArraySecuence<T>* sumarr = new ArraySecuence();
        for (int i = 0; i < arr1->GetLength(); i++) {
            sumarr->Append(arr1->GetIndex(i));
        }
        for (int i = arr1->GetLength(); i < this->GetLength()+arr1->GetLength(); i++) {
            sumarr->Append(this->GetIndex(i - arr1->GetLength()));
        }
        return sumarr;
    }
};


#endif //LAB2_ARRAYSECUENCE_H
