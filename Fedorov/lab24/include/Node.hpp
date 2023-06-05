#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include <iostream>

template<typename T>
class Deque;
template<typename T>
class Iterator;

template <typename T>
class Node {
private:
    T data;
    Node* prev = nullptr;
    Node* next = nullptr;

public:
    friend class Deque<T>;
    friend class Iterator<T>;
    friend class ExpressionTree;

    Node() = default;
    explicit Node(const T& _data);
    Node(const T& _data, Node* _prev, Node* _next);
    ~Node() = default;
};


#include "../src/Node.cpp"
#endif
