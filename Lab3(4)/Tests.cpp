#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree<int> tree;
    int N, element;
    std::cout << "Let me quantity of ellements and these elements: ";
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> element;
        tree.Put(element);
    }
    std::cout << "tree.WidthTraversal(): ";
    tree.WidthTraversal();
    std::cout << std::endl;
    std::cout << "tree.LNR(): ";
    tree.LNR();
    std::cout << std::endl;
    std::cout << "tree.LRN(): ";
    tree.LRN();
    std::cout << std::endl;
    std::cout << "tree.NLR(): ";
    tree.NLR();
    std::cout << std::endl;
    std::cout << "tree.NRL(): ";
    tree.NRL();
    std::cout << std::endl;
    std::cout << "tree.RNL(): ";
    tree.RNL();
    std::cout << std::endl;
    std::cout << "tree.RLN(): ";
    tree.RLN();
    std::cout << std::endl;
    //std::cout << "tree.ToString(): " << tree.ToString(tree.LNR()) << std::endl;
    //std::cout << "tree.WidthTraversal().map([](int a){a /= 2; return a;}: ";
    //tree.map([](int a){
    //    a /= 2;
    //    return a;
    //});
    //std::cout << "tree.WidthTraversal().filter([](int a){a %= 2; return (bool)a;}: ";
    //tree.where([](int a){
    //    a %= 2;
    //    return (bool)a;
    //});
}