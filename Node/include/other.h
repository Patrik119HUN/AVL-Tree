#pragma once

#include <functional>
#include "Node.h"
#include "height.h"
#include "balance.h"

template<typename T>
Node<T>* node_insert(Node<T>* p_node, Node<T>* p_parent, const T &value) {
    if (p_node == nullptr) return new Node<T>(p_parent, value);
    if (value == p_node->value) return p_node;

    if (value < p_node->value) {
        p_node->left = node_insert(p_node->left, p_node, value);
        p_node = balance_node(p_node, value);
    } else {
        p_node->right = node_insert(p_node->right, p_node, value);
        p_node = balance_node(p_node, value);
    }
    p_node->height = std::max(get_height(p_node->left),
                              get_height(p_node->right)) + 1;

    return p_node;
}

template<typename T>
Node<T>* remove(Node<T>* p_node, const T &value) {
    if (p_node == nullptr) return nullptr;

    if (value < p_node->value) p_node->left = remove(p_node->left, value);
    if (value > p_node->value) p_node->right = remove(p_node->right, value);

    if (p_node->left != nullptr && p_node->right != nullptr) {
        auto temp = min_element(p_node->right);
        p_node->value = temp->value;
        p_node->right = remove(p_node->right, p_node->value);
    } else {
        auto temp = p_node;
        if (p_node->left == nullptr) p_node = p_node->right;
        else if (p_node->right == nullptr) p_node = p_node->left;
        delete temp;
    }
    if (p_node == nullptr) return p_node;

    p_node->height = std::max(get_height(p_node->left),
                              get_height(p_node->right)) + 1;

    p_node = balance_node(p_node, value);

    return p_node;
}

template<typename T>
void breadth_first_search(Node<T>* p_node, std::function<void(Node<T>*)> function);

template<typename T>
Node<T>* max_element(Node<T>* p_node) {
    if (p_node == nullptr || p_node->right == nullptr) {
        return p_node;
    }
    return max_element(p_node->right);
}

template<typename T>
Node<T>* min_element(Node<T>* p_node) {
    if (p_node == nullptr || p_node->left == nullptr) {
        return p_node;
    }
    return min_element(p_node->left);
}

