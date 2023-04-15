#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED
#include "Node.hpp"

template <typename T>
class Tree {
private:
    Node<T> *root = nullptr;
public:
    Tree();
    explicit Tree(Node<T>* node);
    Node<T> *get_root();
    void insert_node(T value);
    void print_tree() const;
    void delete_node(T value);
    int64_t count_nodes() const;
    ~Tree();
};

#include "../src/Tree.cpp"

#endif
