#include <iostream>
#include "avl_tree.h"
#include <chrono>
#include "cmath"

Node<int>* test(int a) {
    AVLTree<int> fa;
    auto start = std::chrono::steady_clock::now();
    for (int i = 1; i <= pow(10, a); ++i) {
        fa.insert(i);
    }
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double, std::milli> fp_ms = end - start;
    std::cout << "Overall: " << fp_ms.count() << std::endl;
    std::cout << "Insertion: " << fa.insertion_time.count() << " iterations: " << fa.insert_iterations << std::endl;
    std::cout << "Balance: " << fa.balance_time.count() << " iterations: " << fa.balance_iterations << std::endl;
    std::cout << "Rotations: " << fa.rotations << std::endl;
    std::cout << std::endl;
    return fa.m_root;
}

int main() {
    test(1);
    test(2);
    test(3);
    test(4);
    test(5);
    return 0;
}
