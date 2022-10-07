#include <cassert>
#include "../Secuence.h"
#include "../ArraySecuence.h"
#include "../LinkedListSecuence.h"
#include <iostream>
#include "../Complex.h"

int main() {
    std::cout << "Enter 0 if you work with integers, 1 if you work with real numbers, 2 if you work with complex numbers: ";
    int type;
    std::cin >> type;
    std::cout << "Enter 0 if you are working with LinkedListSecuence, 1 - ArraySecuence: ";
    int sec;
    std::cin >> sec;
    switch (sec) {
        case 0: {
            switch (type) {
                case 0: {
                    Secuence<int> *list = new LinkedListSecuence<int>();
                    int element;
                    std::cout << "Enter the number of elements and then the array elements themselves: ";
                    int N;
                    std::cin >> N;
                    for (int i = 0; i < N; i++) {
                        std::cin >> element;
                        list->Append(element);
                    }
                    std::cout << "Let's start checking the functions using the null element: " << std::endl;
                    std::cout << "list->GetFirst(): " << list->GetFirst() << std::endl;
                    std::cout << "list->GetLast(): " << list->GetLast() << std::endl;
                    std::cout << "list->GetIndex(N/2): " << list->GetIndex(N/2) << std::endl;
                    std::cout << "list->GetSubSecuence(0, N/2): " << list->GetSubSecuence(0, N/2) << std::endl;
                    std::cout << "list->GetLength(): " << list->GetLength() << std::endl;
                    list->Append(0);
                    std::cout << "list->Append(0): " << list << std::endl;
                    list->Prepend(0);
                    std::cout << "list->Prepend(0): " << list << std::endl;
                    list->InsertAt(0, N / 2);
                    std::cout << "list->InsertAt(0, N / 2): " << list << std::endl;
                    std::cout << "Unite(list, list): " << list->Unite(list) <<std::endl;
                    break;
                }
                case 1: {
                    Secuence<double> *list = new LinkedListSecuence<double>();
                    double element;
                    std::cout << "Enter the number of elements and then the array elements themselves: ";
                    int N;
                    std::cin >> N;
                    for (int i = 0; i < N; i++) {
                        std::cin >> element;
                        list->Append(element);
                    }
                    std::cout << "Let's start checking the functions using the null element: " << std::endl;
                    std::cout << "list->GetFirst(): " << list->GetFirst() << std::endl;
                    std::cout << "list->GetLast(): " << list->GetLast() << std::endl;
                    std::cout << "list->GetIndex(N/2): " << list->GetIndex(N/2) << std::endl;
                    std::cout << "list->GetSubSecuence(0, N/2): " << list->GetSubSecuence(0, N/2) << std::endl;
                    std::cout << "list->GetLength(): " << list->GetLength() << std::endl;
                    list->Append(0);
                    std::cout << "list->Append(0): " << list << std::endl;
                    list->Prepend(0);
                    std::cout << "list->Prepend(0): " << list << std::endl;
                    list->InsertAt(0, N / 2);
                    std::cout << "list->InsertAt(0, N / 2): " << list << std::endl;
                    std::cout << "Unite(list, list): " << list->Unite(list) <<std::endl;
                    break;
                }
                case 2: {
                    Secuence<Complex> *list = new LinkedListSecuence<Complex>();
                    Complex element;
                    std::cout << "Enter the number of elements and then the array elements themselves: ";
                    int N;
                    std::cin >> N;
                    for (int i = 0; i < N; i++) {
                        std::cin >> element.Im() >> element.Re();
                        list->Append(element);
                    }
                    std::cout << "Let's start checking the functions using the null element: " << std::endl;
                    std::cout << "list->GetFirst(): " << list->GetFirst() << std::endl;
                    std::cout << "list->GetLast(): " << list->GetLast() << std::endl;
                    std::cout << "list->GetIndex(N/2): " << list->GetIndex(N/2) << std::endl;
                    std::cout << "list->GetSubSecuence(0, N/2): " << list->GetSubSecuence(0, N/2) << std::endl;
                    std::cout << "list->GetLength(): " << list->GetLength() << std::endl;
                    list->Append(0);
                    std::cout << "list->Append(0): " << list << std::endl;
                    list->Prepend(0);
                    std::cout << "list->Prepend(0): " << list << std::endl;
                    list->InsertAt(0, N / 2);
                    std::cout << "list->InsertAt(0, N / 2): " << list << std::endl;
                    std::cout << "Unite(list, list): " << list->Unite(list) <<std::endl;
                    break;
                }
                default: {
                    std::cout << "something wrong" << std::endl;
                }
            }
            break;
        }
        case 1: {
            switch (type) {
                case 0: {
                    Secuence<int> *list = new ArraySecuence<int>();
                    int element;
                    std::cout << "Enter the number of elements and then the array elements themselves: ";
                    int N;
                    std::cin >> N;
                    for (int i = 0; i < N; i++) {
                        std::cin >> element;
                        list->Append(element);
                    }
                    std::cout << "Let's start checking the functions using the null element: " << std::endl;
                    std::cout << "list->GetFirst(): " << list->GetFirst() << std::endl;
                    std::cout << "list->GetLast(): " << list->GetLast() << std::endl;
                    std::cout << "list->GetIndex(N/2): " << list->GetIndex(N/2) << std::endl;
                    std::cout << "list->GetSubSecuence(0, N/2): " << list->GetSubSecuence(0, N/2) << std::endl;
                    std::cout << "list->GetLength(): " << list->GetLength() << std::endl;
                    list->Append(0);
                    std::cout << "list->Append(0): " << list << std::endl;
                    list->Prepend(0);
                    std::cout << "list->Prepend(0): " << list << std::endl;
                    list->InsertAt(0, N / 2);
                    std::cout << "list->InsertAt(0, N / 2): " << list << std::endl;
                    std::cout << "Unite(list, list): " << list->Unite(list) <<std::endl;
                    break;
                }
                case 1: {
                    Secuence<double> *list = new ArraySecuence<double>();
                    double element;
                    std::cout << "Enter the number of elements and then the array elements themselves: ";
                    int N;
                    std::cin >> N;
                    for (int i = 0; i < N; i++) {
                        std::cin >> element;
                        list->Append(element);
                    }
                    std::cout << "Let's start checking the functions using the null element: " << std::endl;
                    std::cout << "list->GetFirst(): " << list->GetFirst() << std::endl;
                    std::cout << "list->GetLast(): " << list->GetLast() << std::endl;
                    std::cout << "list->GetIndex(N/2): " << list->GetIndex(N/2) << std::endl;
                    std::cout << "list->GetSubSecuence(0, N/2): " << list->GetSubSecuence(0, N/2) << std::endl;
                    std::cout << "list->GetLength(): " << list->GetLength() << std::endl;
                    list->Append(0);
                    std::cout << "list->Append(0): " << list << std::endl;
                    list->Prepend(0);
                    std::cout << "list->Prepend(0): " << list << std::endl;
                    list->InsertAt(0, N / 2);
                    std::cout << "list->InsertAt(0, N / 2): " << list << std::endl;
                    std::cout << "Unite(list, list): " << list->Unite(list) <<std::endl;
                    break;
                }
                case 2: {
                    Secuence<Complex> *list = new ArraySecuence<Complex>();
                    Complex element;
                    std::cout << "Enter the number of elements and then the array elements themselves: ";
                    int N;
                    std::cin >> N;
                    for (int i = 0; i < N; i++) {
                        std::cin >> element.Im() >> element.Re();
                        list->Append(element);
                    }
                    std::cout << "Let's start checking the functions using the null element: " << std::endl;
                    std::cout << "list->GetFirst(): " << list->GetFirst() << std::endl;
                    std::cout << "list->GetLast(): " << list->GetLast() << std::endl;
                    std::cout << "list->GetIndex(N/2): " << list->GetIndex(N/2) << std::endl;
                    std::cout << "list->GetSubSecuence(0, N/2): " << list->GetSubSecuence(0, N/2) << std::endl;
                    std::cout << "list->GetLength(): " << list->GetLength() << std::endl;
                    list->Append(0);
                    std::cout << "list->Append(0): " << list << std::endl;
                    list->Prepend(0);
                    std::cout << "list->Prepend(0): " << list << std::endl;
                    list->InsertAt(0, N / 2);
                    std::cout << "list->InsertAt(0, N / 2): " << list << std::endl;
                    std::cout << "Unite(list, list): " << list->Unite(list) <<std::endl;
                    break;
                }
                default: {
                    std::cout << "something wrong" << std::endl;
                }
                break;
            }
        }
        default: {
            std::cout << "something wrong" << std::endl;
        }
    }
}