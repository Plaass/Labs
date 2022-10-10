#ifndef MAIN_CPP_BINARYSEARCHЕREE_H
#define MAIN_CPP_BINARYSEARCHЕREE_H

#include <iostream>
#include <sstream>

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
        if (head -> next == nullptr) return nullptr;
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
    Node* root;
    int len;
public:
    BinarySearchTree(): root(nullptr), len(0) {};
    ~BinarySearchTree() {
        delete [] root;
    }
    void WidthTraversal() {
        std::ostringstream str;
        str << "{ ";
        Node* tmp;
        Queue<Node*> queue = Queue<Node*>();
        queue.Put(root);
        for (int i = 0; i < len; i++) {
            tmp = queue.Pop();
            if (tmp != nullptr) {
                str << tmp -> value << " ";
                if (tmp -> right != nullptr) {
                    queue.Put(tmp -> right);
                }
                if (tmp -> left != nullptr) {
                    queue.Put(tmp -> left);
                }
            }
        }
        std::cout << str.str() << "}" << std::endl;
    }
    void LNR (Node* node) {
        if (node != nullptr) {
            LKP(node->left);
            std::cout << node -> value << std::endl;
            LKP(node->right);
        }
    }
    void LRN (Node* node) {
        if (node != nullptr) {
            LKP(node->left);
            LKP(node->right);
            std::cout << node -> value << std::endl;
        }
    }
    void NLR (Node* node) {
        if (node != nullptr) {
            std::cout << node -> value << std::endl;
            LKP(node->left);
            LKP(node->right);
        }
    }
    void NRL (Node* node) {
        if (node != nullptr) {
            std::cout << node -> value << std::endl;
            LKP(node->right);
            LKP(node->left);
        }
    }
    void RLN (Node* node) {
        if (node != nullptr) {
            LKP(node->right);
            LKP(node->left);
            std::cout << node -> value << std::endl;
        }
    }
    void RNL (Node* node) {
        if (node != nullptr) {
            LKP(node->right);
            std::cout << node -> value << std::endl;
            LKP(node->left);
        }
    }
    BinarySearchTree<T> map(T (*function)(T element)) {

    }
    BinarySearchTree<T> where(bool (*function)(T element)) {

    }

};


#endif //MAIN_CPP_BINARYSEARCHЕREE_H
