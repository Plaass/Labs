#ifndef MAIN_CPP_QUEUE_H
#define MAIN_CPP_QUEUE_H


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



#endif //MAIN_CPP_QUEUE_H
