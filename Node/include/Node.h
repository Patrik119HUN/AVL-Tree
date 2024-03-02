#pragma once

#include <cstdint>
#include <optional>

template<typename T>
class Node {
public:
    Node(Node<T>* p_parent, const T &t_value) : value(t_value), parent(p_parent) {}

    T value;
    Node* parent{nullptr};
    int balance_factor{0};
    uint8_t height{1};
    Node* left{nullptr};
    Node* right{nullptr};

    static std::optional<int> get_balance_factor(Node<T>* node) {
        if (node == nullptr) return {};
        return node->balance_factor;
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &node) {
        os << node.value;
        return os;
    }

};