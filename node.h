#pragma once

#include <cstdint>
#include <ostream>
#include <functional>

template<typename T>
struct Node {
    Node(Node<T>* p_parent, const T &t_value) : value(t_value), parent(p_parent) {}

    T value;
    Node* parent{nullptr};

    uint8_t height{1};
    Node* left{nullptr};
    Node* right{nullptr};

    static uint8_t get_height(Node<T>* p_node) {
        if (p_node == nullptr) return 0;
        return p_node->height;
    }

    static uint8_t update_height(Node<T>* p_node);

    static int get_balance_factor(Node<T>* p_node);

    static Node<T>* insert(Node<T>* p_node, Node<T>* p_parent, const T &value);

    static void breadth_first_search(Node<T>* p_node, std::function<void(Node<T>*)> function);

    static Node<T>* left_rotate(Node<T>* x);

    static Node<T>* right_rotate(Node<T>* y);

    static Node<T>* right_left_rotate(Node<T>* node) {
        node->right = Node<T>::right_rotate(node->right);
        return Node<T>::left_rotate(node);
    }

    static Node<T>* left_right_rotate(Node<T>* node) {
        node->left = Node<T>::left_rotate(node->left);
        return Node<T>::right_rotate(node);
    }

    static Node<T>* max_element(Node<T>* p_node) {
        if (p_node == nullptr || p_node->right == nullptr) {
            return p_node;
        }
        return max_element(p_node->right);
    }

    static Node<T>* min_element(Node<T>* p_node) {
        if (p_node == nullptr || p_node->left == nullptr) {
            return p_node;
        }
        return min_element(p_node->left);
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &node) {
        os << "value: " << node.value;
        return os;
    }
};
