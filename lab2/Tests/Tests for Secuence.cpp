#include <cassert>
#include "../Secuence.h"
#include "../ArraySecuence.h"
#include "../LinkedListSecuence.h"
#include <iostream>

int main() {
    std::cout << "Введите 0, если работаете с целыми числами, 1 - если с вещественными, 2 - если с комплексными: ";
    int type;
    std::cin >> type;
    std::cout << "Введите 0, если работаете с ArraySecuence, 1 - LinkedListSecuence: ";
    int sec;
    std::cin >> sec;
    switch (sec) {
        case 0: {
            switch (type) {
                case 0: {
                    Secuence<int> *list;
                    int element;
                    std::cout << "Введите количвество элементов а затем сами элементы массива: ";
                    int N;
                    std::cin >> N;
                    for (int i = 0; i < N; i++) {
                        std::cin >> element;
                        list->Append(element);
                    }
                    std::cout << "Начнём проверку функций, используя нулевой элемент: " << std::endl;
                    std::cout << "GetFirst(): " << std::endl;
                    std::cout << "GetLast(): " << std::endl;
                    std::cout << "GetIndex(): " << std::endl;
                    std::cout << "GetSubSecuence: " << std::endl;
                    std::cout << "GetLength(): " << std::endl;
                    std::cout << "Append(0): " << std::endl;
                    std::cout << "Prepend(0): " << std::endl;
                    std::cout << "InsertAt(0, N / 2): " << std::endl;
                    std::cout << "Unite(list, list): " << std::endl;
                }
                case 1: {

                }
                case 2: {

                }
                default: {

                }
            }
            break;
        }
        case 1: {

        }
        default: {

        }
    }
}