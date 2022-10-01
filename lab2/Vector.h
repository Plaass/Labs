#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Secuence.h"
#include "LinkedListSecuence.h"
#include "ArraySecuence.h"
#include <iostream>

template<class T>
class Vector {
private:
    Secuence<T> sec = new ArraySecuence<T>();
public:
    Vector() {  };
    void Attend(const T & element) {
        sec.Append(element);
    };
    void Prepend(const T & element) {
        sec.Prepend(element);
    };
    void InsertAt(const T & item, int index){
        sec.InsertAt(index, item);
    };
    T & GetFirst() {
        return sec.GetFirst();
    };

    T & GetLast() {
        return sec.GetLast();
    }

    T & GetIndex(int index) {
        return sec.GetIndex(index);
    };

    int GetLength() {
        return sec.GetLength();
    }

    Vector<T> operator+(const Vector<T> & vector) {
        if (sec.GetLength() != vector.GetLength()) {
            std::cout << "impossible to summ" << std::endl;
            return nullptr;
        }
        else {
            Vector<T> sum = new Vector<T>();
            for (int i = 0; i < sec.GetLength(); i++) {
                Append(sec.GetIndex(i) + vector.GetIndex(i));
            }
            return sum;
        }
    }

    Vector<T> operator*(int scalar) {
        Vector<T> multiply = new Vector<T>();
        for (int i = 0; i < sec.GetLength(); i++) {
            Append(sec.GetIndex(i) * scalar);
        }
        return multiply;
    }

    T Norm() {
        T norm = 0;
        for (int i = 0; i < sec.GetLength(); i++) {
            norm = norm + sqr(sec.GetIndex(i));
        }
        return sqrt(norm);
    }

    T operator*(const Vector<T> & vector) {
        if (sec.GetLength() != vector.GetLength()) {
            std::cout << "impossible to multiply" << std::endl;
            return nullptr;
        }
        else {
            T sum = 0;
            for (int i = 0; i < sec.GetLength(); i++) {
                sum = sum + (sec.GetIndex(i) * vector.GetIndex(i));
            }
            return sum;
        }
    }
};


#endif //LAB2_VECTOR_H
