#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include <iostream>

template <typename T>
class Node {
private:
    T data;
    Node *left = nullptr;
    Node *right = nullptr;

public:
    Node()=default;
    explicit Node(T value);
    T get_data() const;
    T get_left() const;
    T get_right() const;
    void add_leaf(Node *current_node, T value);
    void print_nodes(Node<T> *node, int64_t counter) const;
    void count_nodes(Node* node, int64_t* counter) const;
    Node<T>* min_value_node(Node<T>* node);
    Node<T>* delete_node(Node<T>* current_node, T value);
    void delete_branch(Node<T> *current_node);
    ~Node()=default;
};

#include "../src/Node.cpp"

#endif
