#include "Info-numbers.h"
#include <stdlib.h>

Operations* get_op (void* (*sum)(void* n1, void* n2), void* (*multip)(void* n1, void* n2), void* (*degree)(void* n, int d), char* toString(void* el)) {
    Operations* operation = (Operations*)malloc(sizeof(Operations));
    operation -> sum = sum;
    operation -> multip = multip;
    operation -> degree = degree;
    operation -> toString = toString;
    return operation;
}