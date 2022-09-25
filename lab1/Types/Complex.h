#ifndef UNTITLED_COMPLEX_H
#define UNTITLED_COMPLEX_H

typedef struct MyComplex {
    int re;
    int im;
} MyComplex;

char* toStringComplex(MyComplex* el);
MyComplex* getComplex(int re, int im);
MyComplex* sumC(MyComplex* a, MyComplex* b);
MyComplex* multipC(MyComplex* a, MyComplex* b);
MyComplex* degreeC(MyComplex* a, int b);

#endif //UNTITLED_COMPLEX_H
