#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include <iostream>

class TreeNode {
private:
    char data;
    TreeNode* prev = nullptr;
    TreeNode* next = nullptr;

    TreeNode* get_copy(TreeNode* x);
public:
    friend class ExpressionTree;

    TreeNode() = default;
    explicit TreeNode(const char& _data);
    TreeNode(const char& _data, TreeNode* _prev, TreeNode* _next);
    TreeNode* get_copy();
    ~TreeNode() = default;

    char get_data();
    TreeNode* get_prev();
    TreeNode* get_next();

    void set_data(const char& _data);
    void set_prev(TreeNode *_prev);
    void set_next(TreeNode *_next);
};



#include "../src/TreeNode.cpp"
#endif
