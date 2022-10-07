#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Secuence.h"
#include "LinkedListSecuence.h"
#include "ArraySecuence.h"
#include "Complex.h"
#include <iostream>
#include <cmath>

template<class T, class Container>
class Vector;

template<class T, class Container>
std::ostream& operator<<(std::ostream &out, Vector<T, Container> arr) {
    out << arr.sec->ToString();
    return out;
}


template<class T, class Container = ArraySecuence<T>>
class Vector {
private:
    Secuence<T>* sec = new Container();
public:
    Vector() = default;
    void Attend(const T & element) {
        sec->Append(element);
    };
    void Prepend(const T & element) {
        sec->Prepend(element);
    };
    void InsertAt(const T & item, int index){
        sec->InsertAt(item, index);
    };
    T & GetFirst() {
        return sec->GetFirst();
    };
    const T & GetFirst() const{
        return sec->GetFirst();
    };

    T & GetLast() {
        return sec->GetLast();
    }
    const T & GetLast() const {
        return sec->GetLast();
    }
    T & GetIndex(int index) {
        return sec->GetIndex(index);
    };
    const T & GetIndex(int index) const{
        return sec->GetIndex(index);
    };
    int GetLength(){
        return sec->GetLength();
    }
    const int GetLength() const{
        return sec->GetLength();
    }

    Vector<T, Container> operator+(const Vector<T, Container> & vector) {
            Vector<T, Container> sum = Vector<T, Container>();
            for (int i = 0; i < sec->GetLength(); i++) {
                sum.Attend(sec->GetIndex(i) + vector.GetIndex(i));
            }
            return sum;
    }

    Vector<T, Container> operator*(int scalar) {
        Vector<T, Container> multiply = Vector<T, Container>();
        for (int i = 0; i < sec->GetLength(); i++) {
            multiply.Attend(sec->GetIndex(i) * scalar);
        }
        return multiply;
    }

    T Norm() {
        T norm = 0;
        for (int i = 0; i < sec->GetLength(); i++) {
            norm = norm + (sec->GetIndex(i)) * (sec->GetIndex(i));
        }
        return sqrt(norm);
    }

    T operator*(const Vector<T, Container> & vector) {
            T sum = 0;
            for (int i = 0; i < sec->GetLength(); i++) {
                sum = sum + (sec->GetIndex(i) * vector.GetIndex(i));
            }
            return sum;
    }
    friend std::ostream& operator<<<T>(std::ostream &, Vector);
};


#endif //LAB2_VECTOR_H