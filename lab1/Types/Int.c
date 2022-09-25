#include "Int.h"
#include "stdlib.h"
#include <stdio.h>

char* toStringInt(MyInt* el) {
    if (el == NULL || el -> value == 0) return "0";
    int v = abs(el -> value);
    int counter = 0;
    while (v != 0) {
        v /= 10;
        counter++;
    }
    if (el -> value < 0) {
        counter++;
    }
    v = abs(el -> value);
    char* str = (char*)calloc(counter+1, sizeof(char));
    if (el -> value < 0) {
        *(str + 0) = '-';
        for (int i = 1; i < counter; i++) {
            *(str + counter - i) = '0' + (v % 10);
            v /= 10;
        }
    }
    else {
        for (int i = 0; i < counter; i++) {
            *(str + counter - 1 - i) = '0' + (v % 10);
            v /= 10;
        }
    }
    *(str + counter) = '\0';
    return str;
}

MyInt* getInt(int a) {
    MyInt* n = (MyInt*)malloc(sizeof(MyInt));
    n -> value = a;
    return n;
}

MyInt* sumI(MyInt* a, MyInt* b) {
    MyInt* n = (MyInt*)malloc(sizeof(MyInt));
    n -> value = a -> value + b -> value;
    return n;
}

MyInt* multipI(MyInt* a, MyInt* b) {
    MyInt* n = (MyInt*)malloc(sizeof(MyInt));
    n -> value = a -> value * b -> value;
    return n;
}

MyInt* degreeI(MyInt* a, int b) {
    if (b < 0) {
        printf("it_is_not_int_now\n");
        return 0;
    }
    MyInt* n = (MyInt*)malloc(sizeof(MyInt));
    n -> value = 1;
    for (int i = 0; i < b; i++) {
        n -> value *= a -> value;
    }
    return n;
}