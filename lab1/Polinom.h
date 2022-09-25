#ifndef UNTITLED_POLINOM_H
#define UNTITLED_POLINOM_H

#include "Info-numbers.h"

typedef struct Polinom {
    int len;
    void** array;
    int buffer_len;
    struct Operations* operation;
} Polinom;

void output(Polinom* p);
void* get(Polinom* p, int index);
void add(Polinom* p, int index, void* element);
Polinom* create_pol(Operations* operations);
Polinom* sumP(Polinom* p1, Polinom* p2);
Polinom* mulP(Polinom* p1, Polinom* p2);
Polinom* mul_skalar(Polinom* p, void* skalar);
void* value(Polinom* p, void* x);
Polinom* composition(Polinom* f, Polinom* g);

#endif //UNTITLED_POLINOM_H