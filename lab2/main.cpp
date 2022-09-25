#include <iostream>
#include <vector>

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Secuence.h"


// возвращать ссылки там где это нужно
// разобраться с делегированием полномочий
// принимать ссылки
// пометить функции override
// использовать функции DynamicArray (например getLen())
// разделить sequences по файлам


class A {
public:
    int* p;
    A() {
        p = new int(2);
        std::cout << "A::A()" << std::endl;
    };
    A(const A & other) {
//        p = new int(*other.p);
        std::cout << "A(const A &)" << std::endl;
    }

    A& operator=(const A & other) {
        std::cout << "=(const A &)" << std::endl;
    }

    ~A() {
        delete p;
        std::cout << "~A()" << std::endl;
    }
};
// A()
// foo()

void foo(const A & a) {
    std::cout << "foo" << std::endl;
    return;
}

int main() {
    A a;
    foo(a);

    Secuence<int>* sec = new ListSecuence<int>();




    return 0;
}