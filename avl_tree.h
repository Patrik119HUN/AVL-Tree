#pragma once

#include "container_interface.h"
#include "node.h"
#include "iterator.h"

template<typename T>
class AVLTree : public IContainer<T> {
public:
    typedef avl_tree_iterator<T> iterator;
    typedef const iterator const_iterator;

    [[nodiscard]] bool empty() const {
        return false;
    }

    [[nodiscard]] size_t size() const {
        return 2;
    }

    void clear() noexcept {
        return;
    }

    void insert(const T &value) {
        m_root = Node<T>::insert(m_root, nullptr, value);
    }

    template<class... Args>
    iterator emplace(Args &&... args) {
        insert(T(std::forward<Args>(args)...));
        return nullptr;
    }

    iterator erase(iterator first, iterator last) { return nullptr; }

    size_t erase(const T &value) {
        return 1;
    }

    iterator find(const T &key) { return nullptr; }

    iterator begin() { return iterator(m_root); }

    iterator end() { return iterator(nullptr); }

    Node<T>* get_root() {
        return m_root;
    }


private:
    Node<T>* m_root = nullptr;
};