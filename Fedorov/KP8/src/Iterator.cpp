#include "../include/Iterator.hpp"

template<typename T>
Iterator<T>::Iterator(Node<T> *_node): node(_node) {}

template<typename T>
Node<T>* Iterator<T>::get_node() {
    return node;
}

template<typename T>
T &Iterator<T>::operator*() {
    return node->data;
}

template<typename T>
T &Iterator<T>::operator*() const {
    return node->data;
}

template<typename T>
Iterator<T> Iterator<T>::operator++() {
    if (node != nullptr) {
        node = node->next;
    }
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--() {
    if (node) {
        node = node->prev;
    }
    return *this;
}


template<typename T>
Iterator<T> Iterator<T>::operator+(int64_t val) {
    if (node) {
        if (val > 0) {
            do {
                --val;
                node = node->next;
            } while (val && node);
        } else if (val < 0) {
            do {
                ++val;
                node = node->prev;
            } while (val && node);
        }
    }
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator-(int64_t val) {
    return *this + (-val);
}

template<typename T>
bool Iterator<T>::operator==(Iterator const &x) const {
    return this->node == x.node;
}

template<typename T>
bool Iterator<T>::operator!=(Iterator const &x) const {
    return !(this->node == x.node);
}
