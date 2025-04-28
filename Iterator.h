#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList;

template <typename T>
class Iterator {
private:
    typename DoublyLinkedList<T>::Node* current;
public:
    Iterator(typename DoublyLinkedList<T>::Node* node) : current(node) {}

    T& operator*() {
        return current->data;
    }

    Iterator& operator++() {
        if (current) current = current->next;
        return *this;
    }

    Iterator& operator--() {
        if (current) current = current->prev;
        return *this;
    }

    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }

    bool operator==(const Iterator& other) const {
        return current == other.current;
    }
};

#endif
