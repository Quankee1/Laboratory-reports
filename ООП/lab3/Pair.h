#pragma once
#include <iostream>
using namespace std;
class Pair
{
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();

	void set_data(int, double);
	int get_first();
	Pair& operator = (const Pair&);
	Pair operator - (const Pair&);
	Pair& operator+=(int value);
	Pair& operator+=(double value);

	friend istream& operator>>(istream& in, Pair& other);
	friend ostream& operator << (ostream& out, const Pair& other);
};