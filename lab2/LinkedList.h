#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H

#include <iostream>

template <class T> class LinkedList {
private:
    typedef struct Node {
        Node* next;
        T value;
    };
    Node* head;
    Node* tail;
    int len;
public:
    Node* Node(const T & value): value(value), next(nullptr);
    LinkedList(): len(0), head(Node(nullptr)), tail(nullptr);
    explicit LinkedList(int & len): len(len), head(nullptr), tail(nullptr) {};
    LinkedList(T* & items, int & count) {
        head = Node(nullptr);
        Node* tmp = head;
        for (int i = 0; i < count; i++) {
            tmp -> next = Node(items[i]);
            tmp = tmp -> next;
        }
        tail = tmp;
        len = cout;
    };
    LinkedList(LinkedList <T> & list const) {
        head = Node(nullptr);
        tail = nullptr;
        len = cout;
        Node* tmp1 = head;
        Node* tmp2 = list.head;
        for (int i = 0; i < list.len; i++) {
            tmp1 -> next = Node(tmp2->next->value);
            tmp1 = tmp1 -> next;
            tmp2 = tmp2 -> next;
        }
        tail = tmp1;
    };
    LinkedList<T> & operator=(LinkedList <T> & list const) {
        head = Node(nullptr);
        tail = nullptr;
        len = cout;
        Node* tmp1 = head;
        Node* tmp2 = list.head;
        for (int i = 0; i < list.len; i++) {
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
    T GetFirst() {
        return head -> next -> value;
    }
    T GetLast() {
        return tail -> value;
    }
    T GetIndex(const int & index) {
        if (index < 0 || index >= len) {
            std::coud << "Index out of range" << std::endl;
            return nullptr;
        }
        else {
            Node* tmp = head;
            for(int i = 0; i < index; i++) {
                tmp = tmp -> next;
            }
            return tmp -> next -> value;
        }
    }
    LinkedList<T> GetSubList(const int & start, const int & end) {
        if (start < 0 || start >= len || end < 0 || end >= len || end < start) {
            std::coud << "Something wrong" << std::endl;
            return nullptr;
        }
        else {
            LinkedList<T> list = new LinkedList(end - start + 1);
            Node* tmp = list.head;
            for (int i = start; i <= end; i++) {
                tmp -> next = GetIndex(i);
                tmp = tmp -> next;
            }
            return list;
        }
    }
    int GetLen() {
        return len;
    }
    void Append(const T & element) {
        tail -> next = Node(element);
        tail = tail -> next;
    }
    void Prepend(const T & element) {
        Node* tmp = Node(element);
        tmp -> next = head -> next;
        head -> next = tmp;
    }
    void InsertAt(const int & index, const T & element) {
        Node* tmp = Node(element);
        Node* tmp_go = head;
        for (int i = 0; i < index; i++) {
            tmp_go = tmp_go -> next;
        }
        tmp -> next = tmp_go -> next;
        tmp_go -> next = tmp;
    }
    LinkedList<T> & operator+(const LinkedList<T> & list) {
        LinkedList<T> sum = new LinkedList(list.len + len);
        sum = *this;
        LinkedList<T> tmp = list;
        sum.tail -> next = tmp.head -> next;
        sum.tail = tmp.tail;
        return sum;
    }
};


#endif //LAB2_LINKEDLIST_H
