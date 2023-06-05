#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T &_data): data(_data) {}

template<typename T>
Node<T>::Node(const T &_data, Node<T> *_prev, Node<T> *_next): data(_data), prev(_prev), next(_next) {}

template<typename T>
Node<T> *Node<T>::get_copy(Node<T> *x) {
    if (x == nullptr)
        return nullptr;

    Node<T> *copy = new Node<T>();

    copy->data = x->data;
    copy->prev = get_copy(x->prev);
    copy->next = get_copy(x->next);

    return copy;
}

template<typename T>
Node<T> *Node<T>::get_copy() {
    return get_copy(this);
}

