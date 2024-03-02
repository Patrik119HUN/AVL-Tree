#pragma once

#include "Node.h"
#include "../include/rotations.h"
/*
template<typename T>
int get_balance_factor(Node<T>* p_node) {
    if (p_node == nullptr) return 0;
    int left = get_height(p_node->left);
    int right = get_height(p_node->right);
    return left - right;
}*/

template<typename T>
Node<T>* balance_right(Node<T>* p_node, const T &value) {
    if (value > p_node->right->value) {
        return left_rotate(p_node);
    }
    if (value < p_node->right->value) {
        return right_left_rotate(p_node);
    }
}

template<typename T>
Node<T>* balance_left(Node<T>* p_node, const T &value) {
    if (value < p_node->left->value) {
        return right_rotate(p_node);
    }
    if (value > p_node->left->value) {
        return left_right_rotate(p_node);
    }
}

template<typename T>
inline Node<T>* balance_node(Node<T>* p_node, const T &value) {
    int balance_factor = get_balance_factor(p_node);

    if (balance_factor > 1)return balance_left(p_node, value);
    if (balance_factor < -1) return balance_right(p_node, value);
    return p_node;
}
