#pragma once
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair 
{
    T1 first;
    T2 second;
public:
    Pair() = default;
    Pair(T1 f, T2 s) : first(f), second(s) {}

    Pair<T1, T2> operator-(const Pair<T1, T2>& other) const 
    {
        return Pair<T1, T2>(first - other.first, second - other.second);
    }

    Pair<T1, T2> operator+(int c) const 
    {
        return Pair<T1, T2>(first + c, second);
    }

    Pair<T1, T2> operator+(double c) const
    {
        return Pair<T1, T2>(first, second + c);
    }

    template <typename U1, typename U2>
    friend ostream& operator<<(ostream& out, const Pair<U1, U2>& other);
};

template <typename T1, typename T2>
ostream& operator<<(ostream& out, const Pair<T1, T2>& other) {
    out << other.first << ":" << other.second << " ";
    return out;
}