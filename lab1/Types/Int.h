#ifndef UNTITLED_INT_H
#define UNTITLED_INT_H

typedef struct MyInt {
    int value;
} MyInt;

char* toStringInt(MyInt* el);
MyInt* getInt(int a);
MyInt* sumI(MyInt* a, MyInt* b);
MyInt* multipI(MyInt* a, MyInt* b);
MyInt* degreeI(MyInt* a, int b);

#endif //UNTITLED_INT_H
