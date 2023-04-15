#include "../include/Tree.hpp"


template<typename T>
Tree<T>::Tree() : root(nullptr)
{}

template<typename T>
Tree<T>::Tree(Node<T>* node) {
    this->root=node;
}

template<typename T>
Node<T> *Tree<T>::get_root() {
    return this->root;
}

template<typename T>
int64_t Tree<T>::count_nodes() const {
    int64_t counter = 0;
    root->count_nodes(root, &counter);
    return counter;
}

template<typename T>
void Tree<T>::insert_node(T val) {
    if (root == nullptr) {
        root = new Node(val);
        return;
    }
    root->add_leaf(root, val);
}

template<typename T>
void Tree<T>::delete_node(T value) {
    root = root->delete_node(root, value);
}

template<typename T>
void Tree<T>::print_tree() const {
    root->print_nodes(root, 0);
}

template<typename T>
Tree<T>::~Tree() {
    root->delete_branch(root);
}