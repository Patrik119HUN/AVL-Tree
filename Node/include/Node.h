#pragma once

#include <cstdint>

template<typename T>
class Node {
public:
    Node(Node<T>* p_parent, const T &t_value) : value(t_value), parent(p_parent) {}

    T value;
    Node* parent{nullptr};
    uint8_t height{1};
    Node* left{nullptr};
    Node* right{nullptr};

    friend std::ostream &operator<<(std::ostream &os, const Node &node) {
        os << node.value;
        return os;
    }

};