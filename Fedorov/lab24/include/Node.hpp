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

    Node<T>* get_copy(Node<T>* x);
public:
    friend class Deque<T>;
    friend class Iterator<T>;
    friend class ExpressionTree;

    Node() = default;
    Node(const T& _data);
    Node(const T& _data, Node<T>* _prev, Node<T>* _next);
    Node<T>* get_copy();
    ~Node() = default;

    T get_data();
    Node* get_prev();
    Node* get_next();

    void set_data(const T& _data);
    void set_prev(Node<T> *_prev);
    void set_next(Node<T> *_next);
};



#include "../src/Node.cpp"
#endif
