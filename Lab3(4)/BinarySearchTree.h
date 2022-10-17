#ifndef MAIN_CPP_BINARYSEARCHTREE_H
#define MAIN_CPP_BINARYSEARCHTREE_H

#include <iostream>
#include <sstream>
#include <functional>
#include "Queue.h"

template <class T>
class BinarySearchTree {
private:
    class Node{
    public:
        Node* left;
        Node* right;
        T value;
        Node(): left(nullptr), right(nullptr), value(1) {};
        explicit Node(T element): left(nullptr), right(nullptr), value(element) {};
    };
    Node* root;
public:
    BinarySearchTree(): root(nullptr) {};
    ~BinarySearchTree() {
        delete [] root;
    }
    BinarySearchTree(const BinarySearchTree<T> & tree) {
        root = nullptr;
        tree.WidthTraversal([this](const T & a) {
            this->Put(a);
        });
    }
    BinarySearchTree<T> & operator=(const BinarySearchTree<T> & tree) {
        root = nullptr;
        tree.WidthTraversal([this](const T & a) {
            this->Put(a);
        });
        return *this;
    }
    void WidthTraversal(std::function<void(const T &)> callback = [](const T & a){std::cout << a << " ";}) const {
        Node* tmp = new Node();
        Queue<Node*> queue = Queue<Node*>();
        queue.Put(root);
        while (tmp != nullptr) {
            tmp = queue.Pop();
            if (tmp != nullptr) {
                callback(tmp -> value);
                if (tmp -> right != nullptr) {
                    queue.Put(tmp -> right);
                }
                if (tmp -> left != nullptr) {
                    queue.Put(tmp -> left);
                }
            }
        }
    }
    bool CheckingSearching() {
        return CheckingSearching(nullptr, nullptr, root);
    }
    void read(const std::istringstream & in) {
        T element;
        while (in) {
            in >> element;
            Put(element);
        }
    }
private:
    bool CheckingSearching(Node* left, Node* right, Node* node) {
        if (node == nullptr) {
            return true;

        }
        else if (left == nullptr && right == nullptr) {

        }
        else if (left == nullptr) {
            if (right->value < node->value) {
                return false;
            }
        }
        else if (right == nullptr) {
            if (left->value > node->value) {
                return false;
            }
        }
        return CheckingSearching(left, node->value, node->left) &&
        CheckingSearching(node->value, right, node->right);
    }
    void LNR (Node* node, std::function<void(const T &)> callback = [](const T & a){std::cout << a << " ";}) {
        if (node != nullptr) {
            LNR(node->left, callback);
            callback(node -> value);
            LNR(node->right, callback);
        }
    }
    void LRN (Node* node, std::function<void(const T &)> callback = [](const T & a){std::cout << a << " ";}) {
        if (node != nullptr) {
            LRN(node->left, callback);
            LRN(node->right, callback);
            callback(node -> value);
        }
    }
    void NLR (Node* node, std::function<void(const T &)> callback = [](const T & a){std::cout << a << " ";}) {
        if (node != nullptr) {
            callback(node -> value);
            NLR(node->left, callback);
            NLR(node->right, callback);
        }
    }
    void NRL (Node* node, std::function<void(const T &)> callback = [](const T & a){std::cout << a << " ";}) {
        if (node != nullptr) {
            callback(node -> value);
            NRL(node->right, callback);
            NRL(node->left, callback);
        }
    }
    void RLN (Node* node, std::function<void(const T &)> callback = [](const T & a){std::cout << a << " ";}) {
        if (node != nullptr) {
            RLN(node->right, callback);
            RLN(node->left, callback);
            callback(node -> value);
        }
    }
    void RNL (Node* node, std::function<void(const T &)> callback = [](const T & a){std::cout << a << " ";}) {
        if (node != nullptr) {
            RNL(node->right, callback);
            callback(node -> value);
            RNL(node->left, callback);
        }
    }
public:
    void LNR (std::function<void(const T &)> callback = [](T a){std::cout << a << " ";}) const {
        if (root != nullptr) {
            LNR(root->left, callback);
            callback(root -> value);
            LNR(root->right, callback);
        }
    }
    void LRN (std::function<void(const T &)> callback = [](T a){std::cout << a << " ";}) const {
        if (root != nullptr) {
            LRN(root->left, callback);
            LRN(root->right, callback);
            callback(root -> value);
        }
    }
    void NLR (std::function<void(const T &)> callback = [](T a){std::cout << a << " ";}) const {
        if (root != nullptr) {
            callback(root -> value);
            NLR(root->left, callback);
            NLR(root->right, callback);
        }
    }
    void NRL (std::function<void(const T &)> callback = [](T a){std::cout << a << " ";}) const {
        if (root != nullptr) {
            callback(root -> value);
            NRL(root->right, callback);
            NRL(root->left, callback);
        }
    }
    void RLN (std::function<void(const T &)> callback = [](T a){std::cout << a << " ";}) const {
        if (root != nullptr) {
            RLN(root->right, callback);
            RLN(root->left, callback);
            callback(root -> value);
        }
    }
    void RNL (std::function<void(const T &)> callback = [](T a){std::cout << a << " ";}) const {
        if (root != nullptr) {
            RNL(root->right, callback);
            callback(root -> value);
            RNL(root->left, callback);
        }
    }
    BinarySearchTree<T> map(std::function<T(const T &)> changing) {
        BinarySearchTree<T> tree;
        WidthTraversal([&tree, changing](const T & a) {
            tree.Put(changing(a));
        });
        return tree;
    }
    BinarySearchTree<T> where(std::function<bool(const T &)> filter) {
        BinarySearchTree<T> tree;
        WidthTraversal([&tree, filter](const T & a) {
            if (filter(a)) {
                tree.Put(a);
            }
        });
        return tree;
    }
    void Put(const T & element){
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
        if (root == nullptr) return false;
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
private:
    Node* Search_for_node(const T & element) {
        if (root == nullptr) return nullptr;
        Node* tmp = root;
        while (true) {
            if (element < tmp ->value) {
                if (tmp->left != nullptr) {
                    tmp = tmp->left;
                }
                else {
                    tmp = nullptr;
                    break;
                }
            }
            else if (element > tmp ->value) {
                if (tmp->right != nullptr) {
                    tmp = tmp->right;
                }
                else {
                    tmp = nullptr;
                    break;
                }
            }
            else if (element == tmp ->value) {
                break;
            }
        }
        return tmp;
    }
public:
    BinarySearchTree<T> GetSubTree(const T & element) {
        Node *sub_root = Search_for_node(element);
        if (sub_root== nullptr) {
            return BinarySearchTree<T>();
        }
        BinarySearchTree<T> tree;
        BinarySearchTree<T> treeR;
        tree.root = sub_root;
        treeR = tree;
        tree.root = nullptr;
        return treeR;
    }
    bool SearchSubTree(const BinarySearchTree<T> & subtree) {
        if (subtree.root == nullptr) return false;
        if (Search(subtree.root->value)) {
            BinarySearchTree<T> tree = GetSubTree(subtree.root->value);
            Node* tmp_Verifiable;
            Node* tmp_Verifier;
            Queue<Node*> queue_Verifiable = Queue<Node*>();
            Queue<Node*> queue_Verifier= Queue<Node*>();
            queue_Verifiable.Put(subtree.root);
            queue_Verifier.Put(tree.root);
            tmp_Verifier = queue_Verifier.Pop();
            tmp_Verifiable = queue_Verifiable.Pop();
            while (tmp_Verifiable -> value == tmp_Verifier -> value) {
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
                tmp_Verifier = queue_Verifier.Pop();
                tmp_Verifiable = queue_Verifiable.Pop();
                if (tmp_Verifier == nullptr && tmp_Verifiable == nullptr) {
                    return true;
                }
            }
            return false;
        }
        else {
            return false;
        }
    }
    void Merge(const BinarySearchTree<T> & tree) {
        tree.WidthTraversal([this](const T & a) {
            (*this).Put(a);
        });
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
    }

};


#endif //MAIN_CPP_BINARYSEARCHTREE_H
