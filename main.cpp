#include <iostream>
#include "avl_tree.h"
int main() {
    AVLTree<int> fa;
    fa.insert(2);
    fa.insert(5);
    fa.insert(1);
    fa.insert(4);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
