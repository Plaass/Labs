#ifndef LAB2_DYNAMICARRAY_H
#define LAB2_DYNAMICARRAY_H

#include <iostream>

template <class T> class DynamicArray {
private:
    T* arr;
    int len;
    int buffer_len;
public:
    DynamicArray(): arr(nullptr), len(0), buffer_len(1) {
        arr = new T[1];
    };

    explicit DynamicArray(int len): len(len), buffer_len(2*len) {
        arr = new T[buffer_len];
    };
    DynamicArray(const DynamicArray<T> & array) {
        arr = new T[array.len];
        for (int i = 0; i < array.len; ++i) {
            arr[i] = array.arr[i];
        }
        len = array.len;
        buffer_len = array.buffer_len;
    }
    DynamicArray& operator=(const DynamicArray<T> & array) {
        delete[] arr;
        arr = new T[array.len];
        for (int i = 0; i < array.len; ++i) {
            arr[i] = array.arr[i];
        }
        len = array.len;
        buffer_len = array.buffer_len;
        return *this;
    }
    ~DynamicArray() {
        delete[] arr;
    }
    T & operator[](int index) {
        return arr[index];
    }
    T & at(int index) {
        if (index < 0 || index >= len) {
            throw std::out_of_range("out of range");
        }
        return arr[index];
    }
    T & getT(int index) {
        return arr[index];
    }
    int getLen() {
        return len;
    }
    void addElement(int index, const T & element) {
        if (index < 0) {
            std::cout << "if u want indexes less then zero, u should go python\n";
        }
        else if (index < len) {
            arr[index] = element;
        }
        else {
            if (len == buffer_len) {
                len = index + 1;
                buffer_len = index * 2 + 1;
                arr = (T *) realloc(arr, buffer_len);
                arr[index] = element;
            }
            else {

                len = index + 1;
                arr[index] = element;
            }
        }
    }
    void lenChange(int new_len) {
        len = new_len;
        buffer_len = new_len * 2;
        arr = realloc(arr, buffer_len);
    }
};


#endif //LAB2_DYNAMICARRAY_H
