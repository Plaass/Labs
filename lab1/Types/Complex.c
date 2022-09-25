#include "Complex.h"
#include <stdlib.h>
#include <string.h>

char* toStringComplex(MyComplex* el) {
    if (el == NULL || el -> re == 0 && el -> im == 0) {
        return "0";
    }
    char plus_minus_re;
    char plus_minus_im;
    if (el -> re >= 0) plus_minus_re = '+';
    else if (el -> re < 0) plus_minus_re = '-';
    if (el -> im >= 0) plus_minus_im = '+';
    else if (el -> im < 0) plus_minus_im = '-';
    MyComplex* v = (MyComplex*)malloc(sizeof(MyComplex));
    v -> re = abs(el -> re);
    v -> im = abs(el -> im);
    int lenre = 0;
    int lenim = 0;
    while (v -> re != 0) {
        v -> re /= 10;
        lenre += 1;
    }
    while (v -> im != 0) {
        v -> im /= 10;
        lenim += 1;
    }
    v -> re = abs(el -> re);
    v -> im = abs(el -> im);
    if (v -> re == 0) {
        lenre = 1;
    }
    if (v -> im == 0) {
        lenim = 1;
    }
    int tmp = 0;
    if (plus_minus_re == '-') {
        tmp = 1;
    }
    char* str = (char*)calloc(tmp+lenre+lenim+2, sizeof(char));
    char* tmpre = (char*)calloc(lenre, sizeof(char));
    char* tmpim = (char*)calloc(lenim, sizeof(char));
    for (int i = 0; i < lenre; i++) {
        *(tmpre + i) = '0' + v -> re % 10;
        v -> re /= 10;
    }
    for (int i = 0; i < lenim; i++) {
        *(tmpim + i) = '0' + v -> im % 10;
        v -> im /= 10;
    }
    if (tmp == 1) {
        *(str + 0) = '-';
    }
    for (int i = 0; i < lenre; i++) {
        *(str + tmp + i) = *(tmpre + lenre - 1 - i);
    }
    *(str + tmp + lenre) = plus_minus_im;
    for (int i = 0; i < lenim; i++) {
        *(str + tmp + lenre + 1 + i) = *(tmpim + lenim - 1 - i);
    }
    *(str + tmp + lenre + 1 + lenim) = 'i';
    return str;
}

MyComplex* getComplex(int re, int im) {
    MyComplex* n = (MyComplex*)malloc(sizeof(MyComplex));
    n -> re = re;
    n -> im = im;
    return n;
}

MyComplex* sumC(MyComplex* a, MyComplex* b) {
    MyComplex* n = (MyComplex*)malloc(sizeof(MyComplex*));
    n -> re = a -> re + b -> re;
    n -> im = a -> im + b -> im;
    return n;
}

MyComplex* multipC(MyComplex* a, MyComplex* b) {
    MyComplex* n = (MyComplex*)malloc(sizeof(MyComplex*));
    n -> re = a -> re * b -> re - a -> im * b -> im;
    n -> im = a -> re * b -> im + b -> re * a -> im;
    return n;
}

MyComplex* degreeC(MyComplex* a, int b) {
    MyComplex* n = (MyComplex*)malloc(sizeof(MyComplex*));
    if (b == 0) {
        n -> re = 1;
        n -> im = 0;
        return n;
    }
    n = a;
    for (int i = 1; i < b; i++) {
        n = multipC(n, a);
    }
    return n;
}