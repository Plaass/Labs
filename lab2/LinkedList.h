#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H

#include <iostream>

template <class T> class LinkedList {
private:
    class Node {
    public:
        Node* next;
        T value;
    public:
        Node(): value(0), next(nullptr) {};
        explicit Node(const T & value): value(value), next(nullptr) {};
    };
    Node* head;
    Node* tail;
    int len;

public:
    LinkedList(): len(0), head(new Node()), tail(new Node()) {
        head -> next = tail;
    };
    explicit LinkedList(int len): len(len), head(new Node()), tail(new Node()) {
        Node* tmp = head;
        for (int i = 0; i < len; i++) {
            tmp -> next = new Node();
            tmp = tmp -> next;
        }
        tail = tmp;
    };
    LinkedList(T* items, int count) {
        head = Node(nullptr);
        Node* tmp = head;
        for (int i = 0; i < count; i++) {
            tmp -> next = Node(items[i]);
            tmp = tmp -> next;
        }
        tail = tmp;
        len = count;
    };
    LinkedList(const LinkedList<T> & list) {
        head = Node();
        tail = Node();
        len = list.GetLen();
        Node* tmp1 = head;
        Node* tmp2 = list.head;
        for (int i = 0; i < list.len; i++) {
            tmp1 -> next = new Node(tmp2->next->value);
            tmp1 = tmp1 -> next;
            tmp2 = tmp2 -> next;
        }
        tail = tmp1;
    };
    LinkedList<T> & operator=(const LinkedList <T> & list) {
        head = Node(nullptr);
        tail = nullptr;
        len = list.GetLen();
        Node* tmp1 = head;
        Node* tmp2 = list.head;
        for (int i = 0; i < len; i++) {
            tmp1 -> next = Node(tmp2->next->value);
            tmp1 = tmp1 -> next;
            tmp2 = tmp2 -> next;
        }
        tail = tmp1;
        return *this;
    };
    ~LinkedList() {
        delete head;
        delete tail;
    }
    T & GetFirst() {
        return head -> next -> value;
    }
    T & GetLast() {
        return tail -> value;
    }
    T & GetIndex(int index) {
            Node* tmp = head;
            for(int i = 0; i < index; i++) {
                tmp = tmp -> next;
            }
            return tmp -> next -> value;
    }
    LinkedList<T>* GetSubList(int start, int end) {
        if (start < 0 || start >= len || end < 0 || end >= len || end < start) {
            std::cout << "Something wrong" << std::endl;
            return nullptr;
        }
        LinkedList<T>* list = new LinkedList<T>(end - start + 1);
        Node* it = list->head;
        for (int i = 0; i < start; ++i) {
            it = it->next;
            if (it == nullptr) return nullptr;
        }
        for (int i = start; i < end; ++i) {
            list->Append(it->value);
            it = it->next;
        }
        return list;
    }
    int GetLen() {
        return len;
    }
    void Append(const T & element) {
        if (tail == nullptr) {
            tail = new Node;
        }
        tail -> next = new Node(element);
        tail = tail -> next;
        len++;
    }
    void Prepend(const T & element) {
        Node* tmp = new Node(element);
        tmp -> next = head -> next;
        head -> next = tmp;
        len++;
    }
    void InsertAt(int index, const T & element) {
        Node* tmp = new Node(element);
        Node* tmp_go = head;
        for (int i = 0; i < index; i++) {
            tmp_go = tmp_go -> next;
        }
        tmp -> next = tmp_go -> next;
        tmp_go -> next = tmp;
        len++;
    }
    LinkedList<T> & operator+(const LinkedList<T> & list) {
        LinkedList<T> sum = new LinkedList(list->len + len);
        sum = this;
        LinkedList<T> tmp = list;
        sum.tail -> next = tmp.head -> next;
        sum.tail = tmp.tail;
        return sum;
    }
};


#endif //LAB2_LINKEDLIST_H
