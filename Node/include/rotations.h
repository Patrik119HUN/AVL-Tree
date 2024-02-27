#pragma once

#include "Node.h"

template<typename T>
Node<T>* left_rotate(Node<T>* x) {
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(get_height(x->left),
                         get_height(x->right)) +
                1;
    y->height = std::max(get_height(y->left),
                         get_height(y->right)) +
                1;

    return y;

}

template<typename T>
Node<T>* right_rotate(Node<T>* y) {
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(get_height(y->left),
                         get_height(y->right)) +
                1;
    x->height = std::max(get_height(x->left),
                         get_height(x->right)) +
                1;

    return x;

}

template<typename T>
Node<T>* right_left_rotate(Node<T>* node) {
    node->right = right_rotate(node->right);
    return left_rotate(node);
}

template<typename T>
Node<T>* left_right_rotate(Node<T>* node) {
    node->left = left_rotate(node->left);
    return right_rotate(node);
}
