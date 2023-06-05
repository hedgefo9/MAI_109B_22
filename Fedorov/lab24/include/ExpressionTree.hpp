#ifndef EXPRESSIONTREE_HPP
#define EXPRESSIONTREE_HPP

#include "Node.hpp"
#include <iostream>
#include <string>

class ExpressionTree {
private:
    Node<char> *root;

    size_t find_priority(char c) const;
    bool is_operator(char o) const;
    Node<char>* lab_task(Node<char> *curr_node);
public:

    ExpressionTree();
    explicit ExpressionTree(const std::string &expression);
    ~ExpressionTree();
    Node<char> *get_root() const;

    Node<char> *build_tree(const std::string &postfix_notation);
    void delete_branch(Node<char> *curr_node);
    std::string get_postfix_expr(const std::string &expr);
    void print_postfix_expr(Node<char> *curr_node) const;
    void print_infix_expr(Node<char> *curr_node) const;
    void print_tree(Node<char> *curr_node, const size_t &height = 0) const;
    void lab_task();
};

#include "../src/ExpressionTree.cpp"

#endif