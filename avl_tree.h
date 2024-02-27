#pragma once

#include <vector>
#include <queue>
#include "iterator.h"
#include "Node/helpers.h"
#include "Node/include/Node.h"

template<typename T>
class AVLTree {
public:
    typedef avl_tree_iterator<T> iterator;
    typedef const iterator const_iterator;

    /* Iterator */
    iterator begin() { return iterator(m_root); }

    iterator end() { return iterator(nullptr); }

    const iterator cbegin() const { return const_iterator(m_root); }

    const iterator cend() const { return const_iterator(nullptr); }


    /*----------*/

    [[nodiscard]] bool empty() const {
        return m_root == nullptr;
    }

    [[nodiscard]] size_t size() const {
        return m_size;
    }

    void clear() noexcept {
        return;
    }

    void insert(const T &value) {
        m_root = node_insert(m_root, static_cast<Node<T>*>(nullptr), value);
        m_size++;
    }

    iterator erase(iterator first, iterator last) { return nullptr; }

    size_t erase(const T &value) {
        m_root = remove(m_root, value);
        m_size--;
        return m_size;
    }

    iterator find(const T &key) {
        auto temp = breadth_first_search(m_root, key);
        return iterator(temp);
    }

private:
    size_t m_size;
    Node<T>* m_root = nullptr;
};