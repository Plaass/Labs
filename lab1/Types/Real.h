#ifndef UNTITLED_REAL_H
#define UNTITLED_REAL_H

typedef struct MyFloat {
    float value;
} MyFloat;

char* toStringFloat(MyFloat* el);
MyFloat* getFloat(float a);
MyFloat* sumR(MyFloat* a, MyFloat* b);
MyFloat* multipR(MyFloat* a, MyFloat* b);
MyFloat* degreeR(MyFloat* a, int b);

#endif //UNTITLED_REAL_H
