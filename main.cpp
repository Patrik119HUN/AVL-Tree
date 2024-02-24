#include <iostream>
#include "avl_tree.h"

void preOrder(Node<int>* root) {
    if (root != nullptr) {
        std::cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

AVLTree<int>::iterator iter;

int main() {
    AVLTree<int> fa;
    //fa.emplace(10,20,30,40,50,25);
    fa.insert(10);
    fa.insert(20);
    fa.insert(30);
    fa.insert(40);
    fa.insert(50);
    fa.insert(25);

    for (iter = fa.begin(); iter != fa.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    preOrder(fa.get_root());
    //Node<int>::breadth_first_search(fa.get_root(), [](Node<int>* temp) { std::cout << temp->value << std::endl; });
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
