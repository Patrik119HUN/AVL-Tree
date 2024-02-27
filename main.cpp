#include <iostream>
#include "avl_tree.h"
#include <chrono>

AVLTree<int>::iterator iter;

int main() {
    AVLTree<int> fa;

    auto start = std::chrono::steady_clock::now();
    std::cout << "Doing some work\n";
    for (int i = 0; i < 100000; ++i) {
        fa.insert(i);
    }
    auto end = std::chrono::steady_clock::now();

    // Derive the duration
    std::chrono::duration<double, std::milli> fp_ms = end - start;
    std::chrono::duration<unsigned long long, std::milli> int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << fp_ms.count() << std::endl;
    return 0;
}
