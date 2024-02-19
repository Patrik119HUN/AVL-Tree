#pragma once

#include "container_interface.h"

template<typename T>
struct Node {
    T value;

    Node* parent{nullptr};
    Node* left{nullptr};
    Node* right{nullptr};
};

template<typename T>
class AVLTree {
public:
private:
    Node<T> root;
};