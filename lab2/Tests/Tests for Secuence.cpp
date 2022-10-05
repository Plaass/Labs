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
                    std::cout << "list->GetFirst(): " << list->GetFirst() << std::endl;
                    std::cout << "list->GetLast(): " << list->GetLast() << std::endl;
                    std::cout << "list->GetIndex(N/2): " << list->GetIndex(N/2) << std::endl;
                    std::cout << "list->GetSubSecuence(0, N/2): " << list->GetSubSecuence(0, N/2) << std::endl;
                    std::cout << "list->GetLength(): " << list->GetLength() << std::endl;
                    std::cout << "list->Append(0): " << (list->Append(0)) << std::endl;
                    std::cout << "list->Prepend(0): " << list->Prepend(0) << std::endl;
                    std::cout << "list->InsertAt(0, N / 2): " << list->InsertAt(0, N / 2) << std::endl;
                    std::cout << "Unite(list, list): " << list->Unite(list, list) <<std::endl;
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