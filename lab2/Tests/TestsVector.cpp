#include <cassert>
#include "../Secuence.h"
#include "../Vector.h"
#include "../Complex.h"
#include "../ArraySecuence.h"
#include "../LinkedListSecuence.h"
#include <iostream>

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
                    Vector<int, LinkedListSecuence<int>> list = Vector<int, LinkedListSecuence<int>>();
                    int element;
                    std::cout << "Enter the number of elements and then the array elements themselves: ";
                    int N;
                    std::cin >> N;
                    for (int i = 0; i < N; i++) {
                        std::cin >> element;
                        list.Attend(element);
                    }
                    std::cout << "list: " << list << std::endl;
                    list.Attend(0);
                    std::cout << "list.Attend(0): " << list << std::endl;
                    list.Prepend(0);
                    std::cout << "list.Prepend(0): " << list << std::endl;
                    list.InsertAt(0, N/2);
                    std::cout << "list.InsertAt(0, N/2): " << list << std::endl;
                    std::cout << "list.GetFirst(): " << list.GetFirst() << std::endl;
                    std::cout << "list.GetLast(): " << list.GetLast() << std::endl;
                    std::cout << "list.GetIndex(N/2): " << list.GetIndex(N/2) << std::endl;
                    std::cout << "list.GetLength(): " << list.GetLength() << std::endl;
                    std::cout << "(list + list): " << (list + list) << std::endl;
                    std::cout << "(list * list): " << (list * list) << std::endl;
                    std::cout << "(list * 2): " << (list * 2) << std::endl;
                    std::cout << "list.Norm(): " << list.Norm() << std::endl;
                    break;
                }
                case 1: {
                    Vector<double, LinkedListSecuence<double>> list = Vector<double, LinkedListSecuence<double>>();
                    double element;
                    std::cout << "Enter the number of elements and then the array elements themselves: ";
                    int N;
                    std::cin >> N;
                    for (int i = 0; i < N; i++) {
                        std::cin >> element;
                        list.Attend(element);
                    }
                    std::cout << "list: " << list << std::endl;
                    list.Attend(0);
                    std::cout << "list.Attend(0): " << list << std::endl;
                    list.Prepend(0);
                    std::cout << "list.Prepend(0): " << list << std::endl;
                    list.InsertAt(0, N/2);
                    std::cout << "list.InsertAt(0, N/2): " << list << std::endl;
                    std::cout << "list.GetFirst(): " << list.GetFirst() << std::endl;
                    std::cout << "list.GetLast(): " << list.GetLast() << std::endl;
                    std::cout << "list.GetIndex(N/2): " << list.GetIndex(N/2) << std::endl;
                    std::cout << "list.GetLength(): " << list.GetLength() << std::endl;
                    std::cout << "(list + list): " << (list + list) << std::endl;
                    std::cout << "(list * list): " << (list * list) << std::endl;
                    std::cout << "(list * 2): " << (list * 2) << std::endl;
                    std::cout << "list.Norm(): " << list.Norm() << std::endl;
                    break;
                }
                case 2: {
                    Vector<Complex, LinkedListSecuence<Complex>> list = Vector<Complex, LinkedListSecuence<Complex>>();
                    Complex element;
                    std::cout << "Enter the number of elements and then the array elements themselves: ";
                    int N;
                    std::cin >> N;
                    for (int i = 0; i < N; i++) {
                        std::cin >> element.Re() >> element.Im();
                        list.Attend(element);
                    }
                    std::cout << "list: " << list << std::endl;
                    list.Attend(0);
                    std::cout << "list.Attend(0): " << list << std::endl;
                    list.Prepend(0);
                    std::cout << "list.Prepend(0): " << list << std::endl;
                    list.InsertAt(0, N/2);
                    std::cout << "list.InsertAt(0, N/2): " << list << std::endl;
                    std::cout << "list.GetFirst(): " << list.GetFirst() << std::endl;
                    std::cout << "list.GetLast(): " << list.GetLast() << std::endl;
                    std::cout << "list.GetIndex(N/2): " << list.GetIndex(N/2) << std::endl;
                    std::cout << "list.GetLength(): " << list.GetLength() << std::endl;
                    std::cout << "(list + list): " << (list + list) << std::endl;
                    std::cout << "(list * list): " << (list * list) << std::endl;
                    std::cout << "(list * 2): " << (list * 2) << std::endl;
                    std::cout << "list.Norm(): " << list.Norm() << std::endl;
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
                default: {
                    case 0: {
                        Vector<int> list = Vector<int>();
                        int element;
                        std::cout << "Enter the number of elements and then the array elements themselves: ";
                        int N;
                        std::cin >> N;
                        for (int i = 0; i < N; i++) {
                            std::cin >> element;
                            list.Attend(element);
                        }
                        std::cout << "list: " << list << std::endl;
                        list.Attend(0);
                        std::cout << "list.Attend(0): " << list << std::endl;
                        list.Prepend(0);
                        std::cout << "list.Prepend(0): " << list << std::endl;
                        list.InsertAt(0, N/2);
                        std::cout << "list.InsertAt(0, N/2): " << list << std::endl;
                        std::cout << "list.GetFirst(): " << list.GetFirst() << std::endl;
                        std::cout << "list.GetLast(): " << list.GetLast() << std::endl;
                        std::cout << "list.GetIndex(N/2): " << list.GetIndex(N/2) << std::endl;
                        std::cout << "list.GetLength(): " << list.GetLength() << std::endl;
                        std::cout << "(list + list): " << (list + list) << std::endl;
                        std::cout << "(list * list): " << (list * list) << std::endl;
                        std::cout << "(list * 2): " << (list * 2) << std::endl;
                        std::cout << "list.Norm(): " << list.Norm() << std::endl;
                        break;
                    }
                    case 1: {
                        Vector<double> list = Vector<double>();
                        double element;
                        std::cout << "Enter the number of elements and then the array elements themselves: ";
                        int N;
                        std::cin >> N;
                        for (int i = 0; i < N; i++) {
                            std::cin >> element;
                            list.Attend(element);
                        }
                        std::cout << "list: " << list << std::endl;
                        list.Attend(0);
                        std::cout << "list.Attend(0): " << list << std::endl;
                        list.Prepend(0);
                        std::cout << "list.Prepend(0): " << list << std::endl;
                        list.InsertAt(0, N/2);
                        std::cout << "list.InsertAt(0, N/2): " << list << std::endl;
                        std::cout << "list.GetFirst(): " << list.GetFirst() << std::endl;
                        std::cout << "list.GetLast(): " << list.GetLast() << std::endl;
                        std::cout << "list.GetIndex(N/2): " << list.GetIndex(N/2) << std::endl;
                        std::cout << "list.GetLength(): " << list.GetLength() << std::endl;
                        std::cout << "(list + list): " << (list + list) << std::endl;
                        std::cout << "(list * list): " << (list * list) << std::endl;
                        std::cout << "(list * 2): " << (list * 2) << std::endl;
                        std::cout << "list.Norm(): " << list.Norm() << std::endl;
                        break;
                    }
                    case 2: {
                        Vector<Complex> list = Vector<Complex>();
                        Complex element;
                        std::cout << "Enter the number of elements and then the array elements themselves: ";
                        int N;
                        std::cin >> N;
                        for (int i = 0; i < N; i++) {
                            std::cin >> element.Re() >> element.Im();
                            list.Attend(element);
                        }
                        std::cout << "list: " << list << std::endl;
                        list.Attend(0);
                        std::cout << "list.Attend(0): " << list << std::endl;
                        list.Prepend(0);
                        std::cout << "list.Prepend(0): " << list << std::endl;
                        list.InsertAt(0, N/2);
                        std::cout << "list.InsertAt(0, N/2): " << list << std::endl;
                        std::cout << "list.GetFirst(): " << list.GetFirst() << std::endl;
                        std::cout << "list.GetLast(): " << list.GetLast() << std::endl;
                        std::cout << "list.GetIndex(N/2): " << list.GetIndex(N/2) << std::endl;
                        std::cout << "list.GetLength(): " << list.GetLength() << std::endl;
                        std::cout << "(list + list): " << (list + list) << std::endl;
                        std::cout << "(list * list): " << (list * list) << std::endl;
                        std::cout << "(list * 2): " << (list * 2) << std::endl;
                        std::cout << "list.Norm(): " << list.Norm() << std::endl;
                        break;
                    }
                    std::cout << "something wrong" << std::endl;
                }
            };
            break;
        }
        default: {
            std::cout << "something wrong" << std::endl;
        }
    }
}