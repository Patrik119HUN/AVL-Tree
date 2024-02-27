#pragma once

#include "Node.h"
#include <cstdint>

template<typename T>
uint8_t update_height(Node<T>* p_node) {
    if (p_node == nullptr) return 0;
    p_node->height = 1 + std::max(update_height(p_node->right), update_height(p_node->left));
    return p_node->height;
}

template<typename T>
uint8_t get_height(Node<T>* p_node) {
    if (p_node == nullptr) return 0;
    return p_node->height;
}
