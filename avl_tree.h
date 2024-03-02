#pragma once

#include <vector>
#include <queue>
#include <chrono>
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
        if (m_root == nullptr) {
            m_root = new Node<T>(nullptr, value);
            return;
        }
        auto insertion_start = std::chrono::steady_clock::now();
        Node<T>* current_node = m_root;
        Node<T>* parent_node = m_root;
        while (true) {
            if (value < current_node->value) {
                if (current_node->left == nullptr) {
                    current_node->left = new Node<T>(current_node, value);
                    break;
                } else {
                    parent_node = current_node;
                    current_node = current_node->left;
                }
            } else {
                if (current_node->right == nullptr) {
                    current_node->right = new Node<T>(current_node, value);
                    break;
                } else {
                    parent_node = current_node;
                    current_node = current_node->right;
                }
            }
        }
        auto insertion_end = std::chrono::steady_clock::now();
        insertion_time += insertion_end - insertion_start;
        auto balance_start = std::chrono::steady_clock::now();

        Node<T>* nodeToUpadte = current_node;
        while (nodeToUpadte != nullptr) {
            updateBalance(nodeToUpadte);
            switch (balance_task(nodeToUpadte)) {
                case rotations::LEFT:
                    nodeToUpadte = left_rotate(nodeToUpadte);
                    m_root = nodeToUpadte;
                    break;
                case rotations::RIGHT:
                    nodeToUpadte = right_rotate(nodeToUpadte);
                    m_root = nodeToUpadte;
                    break;
                case rotations::LEFT_RIGHT:
                    nodeToUpadte = left_right_rotate(nodeToUpadte);
                    m_root = nodeToUpadte;
                    break;
                case rotations::RIGHT_LEFT:
                    nodeToUpadte = right_left_rotate(nodeToUpadte);
                    m_root = nodeToUpadte;
                    break;
                case rotations::NONE:
                    break;
            }
            nodeToUpadte = nodeToUpadte->parent;
        }

        auto balance_end = std::chrono::steady_clock::now();
        balance_time += balance_end - balance_start;
        //m_root = rebalance(m_root);
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

    std::chrono::duration<double, std::milli> insertion_time{0};
    std::chrono::duration<double, std::milli> balance_time{0};
private:
    enum class rotations {
        NONE, LEFT, RIGHT, LEFT_RIGHT, RIGHT_LEFT
    };

    rotations balance_task(Node<T>* p_node) {
        if (p_node->balance_factor == 2) {
            auto n_left = Node<T>::get_balance_factor(p_node->left);
            if (n_left.has_value() && *n_left == -1)return rotations::LEFT_RIGHT;
            return rotations::RIGHT;
        }
        if (p_node->balance_factor == -2) {
            auto n_right = Node<T>::get_balance_factor(p_node->right);
            if (n_right.has_value() && *n_right == 1)return rotations::RIGHT_LEFT;
            return rotations::LEFT;
        }
        return rotations::NONE;
    }

    size_t m_size = 0;
    Node<T>* m_root = nullptr;
};