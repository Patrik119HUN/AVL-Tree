#include "node.h"

#include <queue>

template<typename T>
int Node<T>::get_balance_factor(Node<T>* p_node) {
    if (p_node == nullptr) return 0;
    int left = get_height(p_node->left);
    int right = get_height(p_node->right);
    return left - right;
}

template<typename T>
inline Node<T>* balance_right(Node<T>* p_node, const T &value) {
    if (value > p_node->right->value) {
        return Node<T>::left_rotate(p_node);
    }
    if (value < p_node->right->value) {
        return Node<T>::right_left_rotate(p_node);
    }
}

template<typename T>
inline Node<T>* balance_left(Node<T>* p_node, const T &value) {
    if (value < p_node->left->value) {
        return Node<T>::right_rotate(p_node);
    }
    if (value > p_node->left->value) {
        return Node<T>::left_right_rotate(p_node);
    }
}

template<typename T>
inline Node<T>* balance_node(Node<T>* p_node, const T &value) {
    int balance_factor = Node<T>::get_balance_factor(p_node);

    if (balance_factor > 1)return balance_left(p_node, value);
    if (balance_factor < -1) return balance_right(p_node, value);
    return p_node;
}

template<typename T>
Node<T>* Node<T>::insert(Node<T>* p_node, Node<T>* p_parent, const T &value) {
    if (p_node == nullptr) return new Node<T>(p_parent, value);
    if (value == p_node->value) return p_node;

    if (value < p_node->value) {
        p_node->left = insert(p_node->left, p_node, value);
        p_node = balance_node(p_node, value);
    } else {
        p_node->right = insert(p_node->right, p_node, value);
        p_node = balance_node(p_node, value);
    }
    p_node->height = std::max(get_height(p_node->left),
                              get_height(p_node->right)) + 1;

    return p_node;
}

template<typename T>
void Node<T>::breadth_first_search(Node<T>* p_node, std::function<void(Node<T>*)> function) {
    std::queue<Node<T>*> queue;
    queue.push(p_node);
    while (!queue.empty()) {
        Node<T>* temp = queue.front();
        queue.pop();
        function(temp);
        if (temp->left != nullptr) queue.push(temp->left);
        if (temp->right != nullptr) queue.push(temp->right);
    }
}

template<typename T>
uint8_t Node<T>::update_height(Node<T>* p_node) {
    if (p_node == nullptr) return 0;
    p_node->height = 1 + std::max(Node<T>::update_height(p_node->right), Node<T>::update_height(p_node->left));
    return p_node->height;
}

template<typename T>
Node<T>* Node<T>::left_rotate(Node<T>* x) {
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
Node<T>* Node<T>::right_rotate(Node<T>* y) {
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
