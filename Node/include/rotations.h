#pragma once

#include "Node.h"
#include "other.h"

template<typename T>
Node<T>* left_rotate(Node<T>* p_node) {
    auto temp = p_node->right;
    p_node->right = temp->left;

    if (temp->left != nullptr) temp->left->parent = p_node;
    temp->left = p_node;
    temp->parent = p_node->parent;
    p_node->parent = temp;
    update_balance(p_node);
    update_balance(temp);
    return temp;

}

template<typename T>
Node<T>* right_rotate(Node<T>* p_node) {
    auto temp = p_node->left;
    p_node->left = temp->right;

    if (temp->right != nullptr) temp->right->parent = p_node;
    temp->right = p_node;
    temp->parent = p_node->parent;
    p_node->parent = temp;


    update_balance(p_node);
    update_balance(temp);
    return temp;

}

template<typename T>
inline Node<T>* right_left_rotate(Node<T>* node) {
    node->right = right_rotate(node->right);
    return left_rotate(node);
}

template<typename T>
inline Node<T>* left_right_rotate(Node<T>* node) {
    node->left = left_rotate(node->left);
    return right_rotate(node);
}
