#include <stdio.h>
#include <stdlib.h>
#include "../Polinom.h"
#include "../Types/Int.h"

int main() {
    Polinom* p1 = create_pol(get_op(sumI, multipI, degreeI, toStringInt));
    for (int i = 0; i < 2; i++) {
        add(p1, i, getInt(-i-1));
    }
    Polinom* p2 = create_pol(get_op(sumI, multipI, degreeI, toStringInt));
    for (int i = 0; i < 3; i++) add(p2, i, getInt(i+1));
    Polinom* s = sumP(p1, p2);
    Polinom* m = mulP(p1, p2);
    Polinom* c = composition(p1, p2);
    MyInt* v = value(p1, getInt(1));
    Polinom* scal = mul_skalar(p1, getInt(10));
    printf("p1: ");
    output(p1);
    printf("p2: ");
    output(p2);
    printf("p1+p2: ");
    output(s);
    printf("p1*p2: ");
    output(m);
    printf("p1(p2): ");
    output(c);
    printf("p1*10: ");
    output(scal);
    printf("value: ");
    printf("%s\n", toStringInt(v));
}