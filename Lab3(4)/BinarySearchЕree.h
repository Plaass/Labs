#ifndef MAIN_CPP_BINARYSEARCHЕREE_H
#define MAIN_CPP_BINARYSEARCHЕREE_H

#include <iostream>

template <class T>
class Queue {
private:
    class Node{
    public:
        Node* next;
        T value;
        explicit Node(const T & element): next(nullptr), value(element) {};
    };
    Node* head;
    Node* tail;
public:
    Queue(): head(nullptr), tail(nullptr) {};
    ~Queue() {
        delete [] head;
    }
    void Put(const T & element) {
        if (head == nullptr) {
            head = new Node(0);
            tail = new Node(element);
            head -> next = tail;
        }
    };
    T Pop() {
        Node* tmp = head;
        head = head -> next;
        delete [] tmp;
        return head -> value;
    }
};

template <class T>
class BinarySearchTree {
private:
    class Node{
    public:
        Node* left;
        Node* right;
        T value;
        explicit Node(T element): left(nullptr), right(nullptr), value(element) {};
    };
    Node* head;
    int len;
public:
    BinarySearchTree(): head(nullptr), len(0) {};
    ~BinarySearchTree() {
        delete [] head;
    }
    void WidthTraversal() {
        for ()
    }
    BinarySearchTree<T> map(T (*function)(T element)) {

    }
};


#endif //MAIN_CPP_BINARYSEARCHЕREE_H
