#include <iostream>
#include "avl_tree.h"

int main() {
    AVLTree<int> fa;
    fa.insert(2);
    fa.insert(5);
    fa.insert(1);
    fa.insert(4);
    Node<int>::breadth_first_search(fa.get_root(), [](Node<int>* temp) { std::cout << temp->value << std::endl; });
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
