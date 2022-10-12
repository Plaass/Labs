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
public:
    BinarySearchTree(): root(nullptr) {};
    ~BinarySearchTree() {
        delete [] root;
    }
    BinarySearchTree(const BinarySearchTree<T> & tree) {
        Node* tmp;
        delete [] root;
        root = nullptr;
        Queue<Node*> queue = Queue<Node*>();
        queue.Put(tree.root);
        while (tmp != nullptr) {
            tmp = queue.Pop();
            if (tmp != nullptr) {
                this->Put(tmp -> value);
                if (tmp -> right != nullptr) {
                    queue.Put(tmp -> right);
                }
                if (tmp -> left != nullptr) {
                    queue.Put(tmp -> left);
                }
            }
        }
    }
    BinarySearchTree<T> & operator=(const BinarySearchTree<T> & tree) {
        Node* tmp;
        delete [] root;
        root = nullptr;
        Queue<Node*> queue = Queue<Node*>();
        queue.Put(tree.root);
        while (tmp != nullptr) {
            tmp = queue.Pop();
            if (tmp != nullptr) {
                this->Put(tmp -> value);
                if (tmp -> right != nullptr) {
                    queue.Put(tmp -> right);
                }
                if (tmp -> left != nullptr) {
                    queue.Put(tmp -> left);
                }
            }
        }
        return *this;
    }
    void WidthTraversal() {
        std::ostringstream str;
        str << "{ ";
        Node* tmp;
        Queue<Node*> queue = Queue<Node*>();
        queue.Put(root);
        while (tmp != nullptr) {
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
    std::string ToString() {
        std::ostringstream str;
        Node* tmp;
        Queue<Node*> queue = Queue<Node*>();
        queue.Put(root);
        while (tmp != nullptr) {
            tmp = queue.Pop();
            if (tmp != nullptr) {
                str << tmp -> value;
                if (tmp -> right != nullptr) {
                    queue.Put(tmp -> right);
                }
                if (tmp -> left != nullptr) {
                    queue.Put(tmp -> left);
                }
            }
        }
        return str.str();
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
    void LNR_ToString (Node* node, std::ostringstream &out) {
        if (node != nullptr) {
            LKP(node->left);
            out << node -> value;
            LKP(node->right);
        }
    }
    void LRN_ToString (Node* node, std::ostringstream &out) {
        if (node != nullptr) {
            LKP(node->left);
            LKP(node->right);
            out << node -> value;
        }
    }
    void NLR_ToString (Node* node, std::ostringstream &out) {
        if (node != nullptr) {
            out << node -> value;
            LKP(node->left);
            LKP(node->right);
        }
    }
    void NRL_ToString (Node* node, std::ostringstream &out) {
        if (node != nullptr) {
            out << node -> value;
            LKP(node->right);
            LKP(node->left);
        }
    }
    void RLN_ToString (Node* node, std::ostringstream &out) {
        if (node != nullptr) {
            LKP(node->right);
            LKP(node->left);
            out << node -> value;
        }
    }
    void RNL_ToString (Node* node, std::ostringstream &out) {
        if (node != nullptr) {
            LKP(node->right);
            out << node -> value;
            LKP(node->left);
        }
    }
    std::string ToString(void (*function)(Node*, std::ostringstream&)) {
        std::ostringstream str;
        function(root, str);
        return str.str();
    }
    BinarySearchTree<T> map(T (*function)(T element)) {
        Node* tmp;
        BinarySearchTree<T> tree;
        Queue<Node*> queue = Queue<Node*>();
        queue.Put(root);
        while (tmp != nullptr) {
            tmp = queue.Pop();
            if (tmp != nullptr) {
                tree.Put(function(tmp -> value));
                if (tmp -> right != nullptr) {
                    queue.Put(tmp -> right);
                }
                if (tmp -> left != nullptr) {
                    queue.Put(tmp -> left);
                }
            }
        }
        return tree;
    }
    BinarySearchTree<T> where(bool (*function)(T element)) {
        Node* tmp;
        BinarySearchTree<T> tree;
        Queue<Node*> queue = Queue<Node*>();
        queue.Put(root);
        while (tmp != nullptr) {
            tmp = queue.Pop();
            if (tmp != nullptr) {
                if (function(tmp->value)) {
                    tree.Put(tmp->value);
                }
                if (tmp -> right != nullptr) {
                    queue.Put(tmp -> right);
                }
                if (tmp -> left != nullptr) {
                    queue.Put(tmp -> left);
                }
            }
        }
        return tree;
    }
    void Put(const T & element) {
        if (root != nullptr) {
            Node *tmp = root;
            while (true) {
                if (tmp->value > element) {
                    if (tmp->left == nullptr) {
                        tmp->left = new Node(element);
                        break;
                    } else {
                        tmp = tmp->left;
                    }
                } else if (tmp->value < element) {
                    if (tmp->right == nullptr) {
                        tmp->right = new Node(element);
                        break;
                    } else {
                        tmp = tmp->right;
                    }
                } else {
                    break;
                }
            }
        }
        else {
            root = new Node(element);
        }
    }
    bool Search(const T & element) {
        bool flag = false;
        Node* tmp = root;
        while (!flag) {
            if (element < tmp ->value) {
                if (tmp->left != nullptr) {
                    tmp = tmp->left;
                }
                else break;
            }
            else if (element > tmp ->value) {
                if (tmp->right != nullptr) {
                    tmp = tmp->right;
                }
                else break;
            }
            else if (element == tmp ->value) {
                flag = true;
            }
        }
        return flag;
    }
    BinarySearchTree<T> GetSubTree(const T & element) {
        BinarySearchTree<T> tmp_tree;
        if (Search(element)) {
            Node* tmp = root;
            while (true) {
                if (element < tmp ->value) {
                    if (tmp->left != nullptr) {
                        tmp = tmp->left;
                    }
                    else break;
                }
                else if (element > tmp ->value) {
                    if (tmp->right != nullptr) {
                        tmp = tmp->right;
                    }
                    else break;
                }
                else if (element == tmp ->value) {
                    tmp_tree.root = tmp;
                    break;
                }
            }
            return BinarySearchTree<T>(tmp_tree.map);
        }
        else {
            throw std::out_of_range("HaveNoElement");
        }
    }
    bool SearchSubTree(const BinarySearchTree<T> & subtree) {
        if (Search(subtree.root->value)) {
            BinarySearchTree<T> tree = GetSubTree(subtree.root->value);
            Node* tmp_Verifiable;
            Node* tmp_Verifier;
            Queue<Node*> queue_Verifiable = Queue<Node*>();
            Queue<Node*> queue_Verifier= Queue<Node*>();
            queue_Verifiable.Put(subtree.root);
            queue_Verifier.Put(tree.root);
            while (tmp_Verifiable == tmp_Verifier) {
                tmp_Verifier = queue_Verifier.Pop();
                tmp_Verifiable = queue_Verifiable.Pop();
                if (tmp_Verifier != nullptr && tmp_Verifiable != nullptr) {
                    if (tmp_Verifier -> right != nullptr) {
                        queue_Verifier.Put(tmp_Verifier -> right);
                    }
                    if (tmp_Verifiable -> right != nullptr) {
                        queue_Verifiable.Put(tmp_Verifiable -> right);
                    }
                    if (tmp_Verifier -> left != nullptr) {
                        queue_Verifier.Put(tmp_Verifier -> left);
                    }
                    if (tmp_Verifiable -> left != nullptr) {
                        queue_Verifiable.Put(tmp_Verifiable -> left);
                    }
                }
                else if (tmp_Verifier == nullptr && tmp_Verifiable == nullptr) {
                    return true;
                }
            }
            return false;
        }
        else {
            return false;
        }
    }
    void Merge(BinarySearchTree<T> tree) {
        Node* tmp;
        Queue<Node*> queue = Queue<Node*>();
        queue.Put(tree.root);
        while (tmp != nullptr) {
            tmp = queue.Pop();
            if (tmp != nullptr) {
                (*this).Put(tmp->value);
                if (tmp -> right != nullptr) {
                    queue.Put(tmp -> right);
                }
                if (tmp -> left != nullptr) {
                    queue.Put(tmp -> left);
                }
            }
        }
    }
    const T & GetRoot() {
        return root->value;
    }
    const T & Way(const std::string & way) {
        char i = way[0];
        int counter = 0;
        if (root == nullptr) {
            throw std::out_of_range{"way_out_of_range"};
        }
        Node* tmp = root;
        while (i != '\0') {
            if (i == 'R') {
                if (tmp -> right == nullptr) {
                    throw std::out_of_range{"way_out_of_range"};
                }
                tmp = tmp->right;
            }
            else if (i == 'L') {
                if (tmp -> left == nullptr) {
                    throw std::out_of_range{"way_out_of_range"};
                }
                tmp = tmp->left;
            }
            counter++;
            i = way[counter];
        }
        return tmp -> value;
    }
    const T & Way(const T & element, const std::string & way) {
        bool flag = false;
        Node* tmp_start = root;
        while (!flag) {
            if (element < tmp_start ->value) {
                if (tmp_start->left != nullptr) {
                    tmp_start = tmp_start->left;
                }
                else break;
            }
            else if (element > tmp_start ->value) {
                if (tmp_start->right != nullptr) {
                    tmp_start = tmp_start->right;
                }
                else break;
            }
            else if (element == tmp_start ->value) {
                flag = true;
            }
        }
        if (flag) {
            char i = way[0];
            int counter = 0;
            Node *tmp = tmp_start;
            while (i != '\0') {
                if (i == 'R') {
                    if (tmp->right == nullptr) {
                        throw std::out_of_range{"way_out_of_range"};
                    }
                    tmp = tmp->right;
                } else if (i == 'L') {
                    if (tmp->left == nullptr) {
                        throw std::out_of_range{"way_out_of_range"};
                    }
                    tmp = tmp->left;
                }
                counter++;
                i = way[counter];
            }
            return tmp->value;
        }
        else {
            throw std::invalid_argument{"Bad_element"};
        }
    }
};


#endif //MAIN_CPP_BINARYSEARCHЕREE_H
