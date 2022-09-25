#include "Real.h"
#include "stdlib.h"
#include <math.h>

char* toStringFloat(MyFloat* el) {
    if (el == NULL || el -> value == 0) return "0";
    int v = abs(roundf(el -> value * 100));
    int len = 0;
    if (v < 100) {
        len++;
        if (v < 10)
            len++;
    }
    while (v != 0) {
        len++;
        v /= 10;
    }
    v = abs(roundf(el -> value * 100));
    int tmp = 0;
    if (el -> value < 0) tmp = 1;
    char* str = (char*)calloc(tmp+len+1, sizeof(char));
    char* tmpv = (char*)calloc(len, sizeof(char));
    for (int i = 0; i < len; i++) {
        *(tmpv + i) = '0' + v % 10;
        v /= 10;
    }
    if (tmp == 1) {
        *(str + 0) = '-';
    }
    for (int i = 0; i < len; i++) {
        *(str + tmp + i) = *(tmpv + len - 1 - i);
    }
    *(str + tmp + len) = *(str + tmp + len - 1);
    *(str + tmp + len -1) = *(str + tmp + len - 2);
    *(str + tmp + len - 2) = '.';
    return str;
}

MyFloat* getFloat(float a) {
    MyFloat* n = (MyFloat*)malloc(sizeof(MyFloat));
    n -> value = a;
    return n;
}

MyFloat* sumR(MyFloat* a, MyFloat* b) {
    MyFloat* n = (MyFloat*)malloc(sizeof(MyFloat));
    n -> value = a -> value + b -> value;
    return n;
}

MyFloat* multipR(MyFloat* a, MyFloat* b) {
    MyFloat* n = (MyFloat*)malloc(sizeof(MyFloat));
    n -> value = a -> value * b -> value;
    return n;
}

MyFloat* degreeR(MyFloat* a, int b) {
    MyFloat* n = (MyFloat*)malloc(sizeof(MyFloat));
    n -> value = 1;
    for (int i = 0; i < b; i++) {
        n -> value *= a -> value;
    }
    return n;
}