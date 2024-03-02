#pragma once

#include "Node.h"
#include "other.h"

template<typename T>
Node<T>* left_rotate(Node<T>*&x) {
    auto y = x->right;
    auto x_parent = x->parent;

    x->right = y->left;
    y->left = x;

    x->parent = y;
    y->parent = x_parent;

    updateBalance(x);
    updateBalance(y);

    return y;

}

template<typename T>
Node<T>* right_rotate(Node<T>*&p_node) {
    auto temp = p_node->left;
    auto node_parent = p_node->parent;

    p_node->left = temp->right;
    temp->right = p_node;

    p_node->parent = temp;
    temp->parent = node_parent;

    updateBalance(p_node);
    updateBalance(temp);
    return temp;

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
