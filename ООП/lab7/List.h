#pragma once
#include <iostream>
#include "Node.h"
#include "Iterator.h"
using namespace std;

template <typename T>
class List {
    int size;
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    Iterator<T> beg;
    Iterator<T> end;

public:
    List(int s, T value) {
        size = s;
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        head = newNode;
        tail = newNode;
        for (int i = 1; i < size; i++) {
            Node<T>* newNode = new Node<T>;
            newNode->data = value;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        tail->next = nullptr;
        beg.elem = head;
        end.elem = tail->next;
    }

    List(const List<T>& other) {
        Node<T>* temp = other.head;
        while (temp != nullptr) {
            pushback(temp->data);
            temp = temp->next;
        }
        beg = other.beg;
        end = other.end;
    }

    ~List() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    T front() { return head->data; }
    T back() { return tail->data; }

    void pushback(T k) {
        Node<T>* newNode = new Node<T>;
        newNode->data = k;
        if (head == nullptr) {
            head = tail = newNode;
            beg.elem = head;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
        end.elem = tail->next;
    }

    void pushfront(T k) {
        Node<T>* newNode = new Node<T>;
        newNode->data = k;
        if (head == nullptr) {
            head = tail = newNode;
            beg.elem = head;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            beg.elem = head;
        }
        size++;
    }

    void popback() {
        if (tail == nullptr) return;
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
        end.elem = tail ? tail->next : nullptr;
    }

    void popfront() {
        if (head == nullptr) return;
        Node<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        size--;
        beg.elem = head;
    }

    List<T>& operator=(List<T>& other) {
        if (this == &other) return *this;

        while (head != nullptr) {
            popfront();
        }

        Node<T>* current = other.head;
        while (current != nullptr) {
            pushback(current->data);
            current = current->next;
        }
        return *this;
    }

    int operator()() { return size; }

    T& operator[](int index) {
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    List<T> operator*(List<T>& other) {
        int new_size = std::min(size, other.size);
        List<T> new_list(new_size, T());
        for (int i = 0; i < new_size; i++) {
            new_list[i] = (*this)[i] * other[i];
        }
        return new_list;
    }

    Iterator<T> first() { return beg; }
    Iterator<T> last() { return end; }

    template <typename U>
    friend ostream& operator<<(ostream& out, const List<U>& list);

    template <typename U>
    friend istream& operator>>(istream& in, List<U>& list);
};

template <typename T>
ostream& operator<<(ostream& out, const List<T>& list) {
    Node<T>* temp = list.head;
    while (temp != nullptr) {
        out << temp->data << " ";
        temp = temp->next;
    }
    return out;
}

template <typename T>
istream& operator>>(istream& in, List<T>& list) {
    T value;
    while (in >> value) {
        list.pushback(value);
    }
    return in;
}