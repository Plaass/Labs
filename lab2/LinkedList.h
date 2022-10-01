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
        explicit Node(const T & value): value(value), next(nullptr) {};
    };
    Node* head;
    Node* tail;
    int len;

public:
    LinkedList(): len(0), head(Node(nullptr)), tail(nullptr) {};
//  todo  LinkedList(): len(0), head(nullptr), tail(nullptr) {};
    explicit LinkedList(int len): len(len), head(nullptr), tail(nullptr) {};
    LinkedList(T* items, int count) {
        head = Node(nullptr); // todo а здесь???
        Node* tmp = head;
        for (int i = 0; i < count; i++) {
            tmp -> next = Node(items[i]);
            tmp = tmp -> next;
        }
        tail = tmp;
        len = count;
    };
    LinkedList(const LinkedList<T> & list) {
//       todo head = nullptr;
        head = Node(nullptr);
        tail = nullptr;
        len = list.len;
        Node* tmp1 = head;
        Node* tmp2 = list.head;
        for (int i = 0; i < list.len; i++) {
            tmp1 -> next = Node(tmp2->next->value);
//          todo  tmp1 -> next = new Node(tmp2->next->value);
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
        /*if (index < 0 || index >= len) {
            std::cout << "Index out of range" << std::endl;
            return nullptr;
        }
        else {*/
            Node* tmp = head;
            for(int i = 0; i < index; i++) {
                tmp = tmp -> next;
            }
            return tmp -> next -> value;
        //}
    }
    LinkedList<T>* GetSubList(int start, int end) {
        // todo исправить
        if (start < 0 || start >= len || end < 0 || end >= len || end < start) {
            std::cout << "Something wrong" << std::endl;
            return nullptr;
        }
//        LinkedList<T>* list = new LinkedList(end - start + 1);
        auto* list = new LinkedList<T>();
//        Node* tmp = list->head;
        Node* it = list->head;
        for (int i = 0; i < start; ++i) {
            it = it->next;
            if (it == nullptr) return nullptr;
        }
        for (int i = start; i < end; ++i) {
            list->Append(it->value);
            it = it->next;
        }


//        for (int i = start; i <= end; i++) {
//            tmp -> next = GetIndex(i);
//            tmp = tmp -> next;
//        }
        return list;
    }
    int GetLen() {
        return len;
    }
    void Append(const T & element) {
//      todo  tail -> next = new Node(element);
        tail -> next = Node(element);
        tail = tail -> next;
    }
    void Prepend(const T & element) {
//      todo  Node* tmp = new Node(element);
        Node* tmp = Node(element);
        tmp -> next = head -> next;
        head -> next = tmp;
    }
    void InsertAt(int index, const T & element) {
//      todo  Node* tmp = new Node(element);
        Node* tmp = Node(element);
        Node* tmp_go = head;
        for (int i = 0; i < index; i++) {
            tmp_go = tmp_go -> next;
        }
        tmp -> next = tmp_go -> next;
        tmp_go -> next = tmp;
    }
    LinkedList<T> & operator+(const LinkedList<T> & list) {
        // todo в этой функции есть какая-то проблема
        //  и чисто синтаксическая, и логическая

        LinkedList<T> sum = new LinkedList(list.len + len);
        sum = *this;
        LinkedList<T> tmp = list;
        sum.tail -> next = tmp.head -> next;
        sum.tail = tmp.tail;
        return sum;
    }
};


#endif //LAB2_LINKEDLIST_H
