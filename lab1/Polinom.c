#include "Polinom.h"
#include <stdlib.h>
#include <stdio.h>

Polinom* create_pol_empty(int len, Operations* operations) {
    Polinom* polinom = (Polinom*)malloc(sizeof(Polinom));
    polinom -> buffer_len = 2*len;
    polinom -> len = len;
    polinom -> array = (void**)calloc(polinom -> buffer_len, sizeof(void*));
    polinom -> operation = operations;
    return polinom;
}

Polinom* create_pol(Operations* operations) {
    Polinom* polinom = (Polinom*)malloc(sizeof(Polinom));
    polinom -> buffer_len = 10;
    polinom -> len = 0;
    polinom -> array = (void**)calloc(polinom -> buffer_len, sizeof(void*));
    polinom -> operation = operations;
    return polinom;
}

void output(Polinom* p) {
    for (int i = 0; i < p -> len; i++) {
        printf("(%s)*x^%d", p->operation->toString(get(p, i)), i);
        if (i != p -> len - 1) printf(" + ");
    }
    printf("\n\n");
}

void* get(Polinom* p, int index) {
    if (index >=0 && index < p ->len) return *(p -> array + index);
    else return NULL;
}

void add(Polinom* p, int index, void* element) {
    if (index >= p -> len) {
        p -> len = index + 1;
        if (p->len >= p->buffer_len) {
            p->buffer_len += p -> len;
            p->array = (void **) realloc(p->array, p->buffer_len * sizeof(void *));
        }
        *(p->array + index) = element;
    }
    else if (index < 0) {
        printf("Out_of_range\n");
    }
    else *(p -> array + index) = element;
}

Polinom* sumP(Polinom* p1, Polinom* p2) {
    Polinom* p = create_pol(p2->operation);
    int min;
    if (p1 -> len < p2 -> len) {
        for (int i = 0; i < p1 -> len; i++) {
            if (*(p1 -> array + i) == NULL) add(p, i, *(p2 -> array + i));
            else if (*(p2 -> array + i) == NULL) add(p, i, *(p1 -> array + i));
            else add(p, i, p->operation->sum(*(p1 -> array + i), *(p2 -> array + i)));
        }
        for (int i = p1 -> len; i < p2 -> len; i++) {
            if (*(p1 -> array + i) == NULL) add(p, i, *(p2 -> array + i));
            else if (*(p2 -> array + i) == NULL) add(p, i, *(p1 -> array + i));
            else add(p, i, *(p2 -> array + i));
        }
    }
    else {
        for (int i = 0; i < p2 -> len; i++) {
            add(p, i, p->operation->sum(*(p1 -> array + i), *(p2 -> array + i)));
        }
        for (int i = p2 -> len; i < p1 -> len; i++) {
            add(p, i, *(p1 -> array + i));
        }
    }
    return p;
}

Polinom* mulP(Polinom* p1, Polinom* p2) {
    int len = p1 -> len + p2 -> len;
    Polinom* p = create_pol_empty(len-1, p1 -> operation);
    for (int k = 0; k < p1 -> len; k++) {
        for (int j = 0; j < p2 -> len; j++) {
            if (*(p2 -> array + j) == NULL || *(p1 -> array + k) == NULL) continue;
            else if (*(p -> array + k+j) == NULL ) *(p -> array + k+j) = p->operation->multip(*(p1 -> array + k), *(p2 -> array + j));
            else *(p -> array + k+j) = p->operation->sum(*(p -> array + k+j), p->operation->multip(*(p1 -> array + k), *(p2 -> array + j)));
        }
    }
    return p;
}

Polinom* mul_skalar(Polinom* p, void* skalar) {
    Polinom* pol = create_pol_empty(p -> len, p -> operation);
    for (int i = 0; i < p -> len; i++) *(pol -> array + i) = p->operation->multip(*(p -> array + i), skalar);
    return pol;
}

void* value(Polinom* p, void* x) {
    void* value = *(p -> array + 0);
    for (int i = 1; i < p -> len; i++) {
        value = p->operation->sum(value, p->operation->multip(*(p -> array + i), p->operation->degree(x, i)));
    }
    return value;
}

Polinom* degreeP(Polinom* p, int n) {
    if (n < 0) {
        printf("is_not_a_polinom_now\n");
        return p;
    }
    Polinom* d = create_pol_empty(p -> len, p -> operation);
    for (int i = 0; i <= p -> len; i++) {
        *(d -> array + i) = *(p -> array + i);
    }
    for (int i = 1; i < n; i++) {
        d = mulP(d, p);
    }
    return d;
}

Polinom* composition(Polinom* f, Polinom* g) {
    int len = (f -> len-1)*(g -> len-1)+1;
    Polinom* p = create_pol_empty(len, f -> operation);
    Polinom* d = create_pol(f -> operation);
    for (int i = 0; i < f -> len; i++) {
            if (i != 0)
                d = degreeP(g, i);
            for (int j = 0; j < d -> len; j++) {
                if (*(p -> array + j) == NULL)
                    *(p -> array + j) = p -> operation -> multip(*(f -> array + i), *(d -> array + j));
                else
                    *(p -> array + j) = p -> operation -> sum(*(p -> array + j), p -> operation -> multip(*(f -> array + i), *(d -> array + j)));
            }
    }
    return p;
}