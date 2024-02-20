#pragma once

#include "container_interface.h"

template<typename T>
struct Node {
    Node(Node<T>* p_parent, const T &t_value) : value(t_value), parent(p_parent) {}

    T value;

    uint8_t height{0};

    Node* parent{nullptr};
    Node* left{nullptr};
    Node* right{nullptr};

    static uint8_t get_height(Node<T>* p_node) {
        if (p_node == nullptr) return 0;
        return p_node->height;
    }

    static uint8_t get_balance_factor(Node<T>* p_node) {
        if (p_node == nullptr) return 0;
        return get_height(p_node->left) - get_height(p_node->right);
    }

    uint8_t get_height() { return this->height; }

    uint8_t get_balance_factor() { return Node<T>::get_balance_factor(this); }

    static Node<T>* insert(Node<T>* p_node, Node<T>* p_parent, const T &value) {
        if (p_node == nullptr) {
            p_node = new Node<T>(p_parent, value);
            return p_node;
        }
        if (p_node->value > value) {
            p_node->right = insert(p_node->right, p_node, value);
        } else { p_node->left = insert(p_node->left, p_node, value); }
        //find_hegiht(p_node);
        p_node->height = 1 + std::max(get_height(p_node->right), get_height(p_node->left));
        return p_node;
    }

    static void breadth_first_search(Node<T>* p_node, std::function<void(Node<T>*)> function) {
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

    static void left_rotate(Node<T>* p_node) {

    }

    static void right_rotate(Node<T>* p_node) {

    }
};

template<typename T>
uint8_t find_hegiht(Node<T>* t_node) {
    if (t_node == nullptr) return -1;
    uint8_t height = -1;
    std::queue<Node<T>*> queue;
    queue.push(t_node);
    while (!queue.empty()) {
        size_t size = queue.size();
        height++;
        while (size > 0) {
            Node<T>* temp = queue.front();
            queue.pop();

            if (temp->left != nullptr) queue.push(temp->left);
            if (temp->right != nullptr) queue.push(temp->right);

            size--;

        }
    }
    return height;

}

template<typename T>
class AVLTree : public IContainer<T> {
public:
    struct iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = Node<T>;

        explicit iterator(Node<T>* p_node) {
            queue.push(p_node);
        }

        Node<T> &operator*() const { return *m_ptr; }

        Node<T>* operator->() { return m_ptr; }

        // Prefix increment
        iterator &operator++() {
            Node<T>* temp = queue.front();
            queue.pop();

            if (temp->left != nullptr) queue.push(temp->left);
            if (temp->right != nullptr) queue.push(temp->right);
            return *this;
        }

        // Postfix increment
        const iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const iterator &a, const iterator &b) { return a.m_ptr == b.m_ptr; };

        friend bool operator!=(const iterator &a, const iterator &b) { return a.m_ptr != b.m_ptr; };
    private:
        std::queue<Node<T>*> queue;
        Node<T>* m_ptr;
    };

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
        if (m_root == nullptr) {
            m_root = new Node<T>(nullptr, value);
            return;
        }
        Node<T>::insert(m_root, nullptr, value);
    }

    void erase(const T &value) {
        return;
    }

    iterator begin() { return iterator(m_root); }

    Node<T>* get_root() {
        return m_root;
    }

private:
    Node<T>* m_root = nullptr;
};