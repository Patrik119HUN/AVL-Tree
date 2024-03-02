#include <iostream>
#include "avl_tree.h"
#include <chrono>

int main() {
    AVLTree<int> fa;
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000; ++i) {
        fa.insert(i);
    }
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double, std::milli> fp_ms = end - start;

    std::cout << "Overall: " << fp_ms.count() << std::endl;
    std::cout << "Insertion: " << fa.insertion_time.count() << std::endl;
    std::cout << "Balance: " << fa.balance_time.count() << std::endl;
    return 0;
}
