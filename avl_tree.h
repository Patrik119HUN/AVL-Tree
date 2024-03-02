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
        while (true) {
            if (value < current_node->value) {
                if (current_node->left == nullptr) {
                    current_node->left = new Node<T>(current_node, value);
                    current_node = current_node->left;
                    break;
                } else {
                    current_node = current_node->left;
                }
            } else {
                if (current_node->right == nullptr) {
                    current_node->right = new Node<T>(current_node, value);
                    current_node = current_node->right;
                    break;
                } else {
                    current_node = current_node->right;
                }
            }
            insert_iterations++;
        }
        auto insertion_end = std::chrono::steady_clock::now();
        insertion_time += insertion_end - insertion_start;
        auto balance_start = std::chrono::steady_clock::now();

        Node<T>* node_to_update = current_node;
        while (node_to_update != nullptr) {
            auto parent_node = node_to_update->parent;
            if (parent_node == nullptr) break;
            (node_to_update == parent_node->left) ? parent_node->balance_factor-- : parent_node->balance_factor++;
            if (parent_node->balance_factor == 0) break;
            if (parent_node->balance_factor == -2) {
                auto n_left = Node<T>::get_balance_factor(parent_node->left);
                parent_node = (n_left.has_value() && *n_left == 1) ? left_right_rotate(parent_node) : right_rotate(parent_node);
                (parent_node->parent == nullptr) ? m_root = parent_node : parent_node->parent->left = parent_node;
                rotations++;
                break;
            }
            if (parent_node->balance_factor == 2) {
                auto n_right = Node<T>::get_balance_factor(parent_node->right);
                parent_node = (n_right.has_value() && *n_right == -1) ? right_left_rotate(parent_node) : left_rotate(parent_node);
                (parent_node->parent == nullptr) ? m_root = parent_node : parent_node->parent->right = parent_node;
                rotations++;
                break;
            }
            node_to_update = parent_node;
            balance_iterations++;
        }

        auto balance_end = std::chrono::steady_clock::now();
        balance_time += balance_end - balance_start;
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
    int insert_iterations = 0;
    int balance_iterations = 0;
    int rotations = 0;
    Node<T>* m_root = nullptr;
private:
    size_t m_size = 0;
};