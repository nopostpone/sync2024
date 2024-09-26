// TODO
#include <iostream>

template <typename T>
struct Node {
    T val;
    Node<T> *prev;
    Node<T> *next;

    Node(const T &_val = {}) : val(_val), prev(nullptr), next(nullptr) {}

    ~Node() {}
};