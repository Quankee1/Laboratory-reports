#pragma once
#include "Node.h"

template <typename T>
class Iterator {
    Node<T>* elem;
public:
    Iterator() : elem(nullptr) {}
    Iterator(const Iterator<T>& other) : elem(other.elem) {}

    Iterator<T> operator++(int) {
        Iterator<T> temp = *this;
        elem = elem->next;
        return temp;
    }

    Iterator<T> operator--(int) {
        Iterator<T> temp = *this;
        elem = elem->prev;
        return temp;
    }

    Iterator<T> operator+(int n) {
        Iterator<T> temp = *this;
        for (int i = 0; i < n; i++) {
            temp.elem = temp.elem->next;
        }
        return temp;
    }

    Iterator<T> operator-(int n) {
        Iterator<T> temp = *this;
        for (int i = 0; i < n; i++) 
        {
            temp.elem = temp.elem->prev;
        }
        return temp;
    }

    T& operator*() {
        return elem->data;
    }

    bool operator==(const Iterator<T>& other) const {
        return elem == other.elem;
    }

    bool operator!=(const Iterator<T>& other) const {
        return elem != other.elem;
    }

    template <typename U> friend class List;
};