#pragma once
#include <iostream>
using namespace std;

class Pair 
{
    int first;
    double second;
public:
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}

    
    bool operator<(const Pair& other) const 
    {
        return (first < other.first) ||
            (first == other.first && second < other.second);
    }

    Pair operator+(const Pair& other) const 
    {
        return Pair(first + other.first, second + other.second);
    }

    Pair& operator+=(const Pair& other)
    {
        first += other.first;
        second += other.second;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Pair& p) 
    {
        return out << p.first << ":" << p.second;
    }

    friend istream& operator>>(istream& in, Pair& p) {
        return in >> p.first >> p.second;
    }

    // Методы доступа
    int get_first() const { return first; }
    double get_second() const { return second; }
};