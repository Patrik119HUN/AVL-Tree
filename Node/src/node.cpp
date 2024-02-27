#include <queue>
#include <functional>
#include "../include/other.h"

template<typename T>
void breadth_first_search(Node<T>* p_node, std::function<void(Node<T>*)> function) {
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