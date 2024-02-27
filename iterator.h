#pragma once

#include <stack>
#include "Node/include/Node.h"

template<typename T>
struct avl_tree_iterator {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Node<T>;

    avl_tree_iterator() = default;

    explicit avl_tree_iterator(Node<T>* p_node) {
        auto temp = p_node;
        while (temp != nullptr) {
            m_stack.push(temp);
            temp = temp->left;
        }
    }

    Node<T>* operator->() { return m_stack.top(); }

    // Prefix increment
    avl_tree_iterator &operator++() {
        auto temp = m_stack.top()->right;
        m_stack.pop();
        while (temp != nullptr) {
            m_stack.push(temp);
            temp = temp->left;
        }
        return *this;
    }

    // Postfix increment
    const avl_tree_iterator operator++(int) {
        avl_tree_iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    friend bool operator==(const avl_tree_iterator &a, const avl_tree_iterator &b) { return a.m_stack == b.m_stack; };

    friend bool operator!=(const avl_tree_iterator &a, const avl_tree_iterator &b) { return a.m_stack != b.m_stack; };

    T operator*() const noexcept {
        return this->m_stack.top()->value;
    }

private:
    std::stack<Node<T>*>
            m_stack;
};
