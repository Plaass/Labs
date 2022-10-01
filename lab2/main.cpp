#include <iostream>

#include "Vector.h"
#include "Complex.h"

/*
 * Тестики
 * Доделать
 * по минималке
 */

int main() {
    /* выдает segfault */
    auto v2 = Vector<int, LinkedListSecuence<int>>();

    auto v3 = v2 * 2;
    for (int i = 0; i < v3.GetLength(); ++i) {
        std::cout << v3.GetIndex(i) << std::endl;
    }
    /* выдает segfault */

    return 0;
}