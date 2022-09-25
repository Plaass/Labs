#ifndef UNTITLED_INFO_NUMBERS_H
#define UNTITLED_INFO_NUMBERS_H

typedef struct Operations {
    void* (*sum)(void* n1, void* n2);
    void* (*multip)(void* n1, void* n2);
    void* (*degree)(void* n, int d);
    char* (*toString)(void* el);
} Operations;

Operations* get_op(void* (*sum)(void* n1, void* n2), void* (*multip)(void* n1, void* n2), void* (*degree)(void* n, int d), char* toString(void* el));

#endif //UNTITLED_INFO_NUMBERS_H