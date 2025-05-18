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

    Pair operator-(const Pair& other) const
    {
        return Pair(first - other.first, second - other.second);
    }

    Pair& operator+=(int value)
    {
        first += value;
        return *this;
    }

    Pair& operator+=(double value)
    {
        second += value;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Pair& p)
    {
        return out << p.first << ":" << p.second;
    }

    friend istream& operator>>(istream& in, Pair& p)
    {
        cout << "Enter int and double: ";
        return in >> p.first >> p.second;
    }

    bool operator>=(const Pair& other) const 
    {
        return (first >= other.first) && (second >= other.second);
    }

    bool operator<=(const Pair& other) const 
    {
        return (first <= other.first) && (second <= other.second);
    }

    Pair operator/(int divisor) const 
    {
        return Pair(first / divisor, second / divisor);
    }

    Pair& operator+=(const Pair& other) 
    {
        first += other.first;
        second += other.second;
        return *this;
    }

    bool operator<(const Pair& other) const 
    {
        return first < other.first && second < other.second;
    }

    bool operator>(const Pair& other) const 
    {
        return first > other.first && second > other.second;
    }

    Pair operator+(const Pair& other) const 
    {
        return Pair(first + other.first, second + other.second);
    }

    // Методы доступа
    int get_first() const { return first; }
    double get_second() const { return second; }
};
