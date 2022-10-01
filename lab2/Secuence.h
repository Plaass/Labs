#ifndef LAB2_SECUENCE_H
#define LAB2_SECUENCE_H

#include "DynamicArray.h"
#include "LinkedList.h"

#include <iostream>

template <class T> class Secuence {
public:
    virtual T & GetFirst() = 0;

    virtual T & GetLast() = 0;

    virtual T & GetIndex(int index) = 0;

    virtual Secuence<T> GetSubSecuence(int startindex, int endindex) = 0;

    virtual int GetLength() = 0;

    virtual void Append(const T & item) = 0;

    virtual void Prepend (const T & item) = 0;

    virtual void InsertAt(const T & item, int index) = 0;

    Secuence<T> operator+(const Secuence<T> & arr1) = 0;
};


#endif //LAB2_SECUENCE_H
