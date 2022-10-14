#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree<int> tree;
    BinarySearchTree<int> tree2;
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
    std::cout << "tree.map([](int a){return a/2;}).WidthTraversal(): ";
    tree2 = tree.map([](int a){
        return a / 2;
    });
    tree2.WidthTraversal();
    std::cout << std::endl;
    std::cout << "tree.filter([](int a){(bool)(a %= 2);}).WidthTraversal(): ";
    tree2 = tree.where([](int a){
        return (bool)(a%2);
    });
    tree2.WidthTraversal();
    std::cout << std::endl;
    std::cout << "tree.Put(100): ";
    tree.Put(100);
    tree.WidthTraversal();
    std::cout << std::endl;
    std::cout << "tree.Search(100) tree.Search(0): " << tree.Search(100) << " " << tree.Search(0) << std::endl;
    std::cout << "tree.GetSubTree(100) and tree.GetSubTree(0): ";
    tree2 = tree.GetSubTree(100); //?
    tree2.WidthTraversal();
    std::cout << " and ";
    tree2 = tree.GetSubTree(0);
    tree2.WidthTraversal();
    std::cout << std::endl;
    std::cout << "tree.SearchSubTree(tree.GetSubTree(100)) and tree.SearchSubTree(tree.GetSubTree(0)): " << tree.SearchSubTree(tree.GetSubTree(100)) << " and " << tree.SearchSubTree(tree.GetSubTree(0)) << std::endl;
    std::cout << "tree.Merge(tree.GetSubTree(100)): ";
    tree.Merge(tree.GetSubTree(100));
    tree.WidthTraversal();
    std::cout << std::endl;
    std::cout << "tree.GetRoot(): " << tree.GetRoot() << std::endl;
    std::cout << "tree.Way(RLRR): " << tree.Way("RLRR") << std::endl;
    std::cout << "tree.Way(100, RLRR): " << tree.Way(100,"RLRR") << std::endl;
}