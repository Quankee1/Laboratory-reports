#pragma once
#include "Object.h"
#include "Event.h"
#include <iostream>

class Vector 
{
protected:
    Object** beg;  // Указатель на массив указателей
    int size;      // Максимальный размер
    int cur;       // Текущая позиция
public:
    Vector(int n = 0);
    virtual ~Vector();

    void Add(Object*);
    void Show();
    void HandleEvent(const TEvent&);
    int operator()();  // Возвращает текущее количество элементов
};

Vector::Vector(int n) 
{
    beg = new Object * [n];
    size = n;
    cur = 0;
}

Vector::~Vector() 
{
    if (beg != nullptr) {
        for (int i = 0; i < cur; i++)
            delete beg[i];
        delete[] beg;
    }
}

void Vector::Add(Object* p) 
{
    if (cur < size) {
        beg[cur] = p;
        cur++;
    }
}

void Vector::Show() {
    if (cur == 0) cout << "\nEmpty";
    Object** p = beg;
    for (int i = 0; i < cur; i++)
    {
        (*p)->Show();
        p++;
    }
}

void Vector::HandleEvent(const TEvent& e)
{
    Object** p = beg;
    for (int i = 0; i < cur; i++) 
    {
        (*p)->HandleEvent(e);
        p++;
    }
}

int Vector::operator()() 
{
    return cur;
}