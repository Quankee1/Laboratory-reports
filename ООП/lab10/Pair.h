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
	int get_first() const;
	double get_second() const { return second; }
	Pair& operator = (const Pair&);
	Pair operator - (const Pair&);
	Pair& operator+=(int value);
	Pair& operator+=(double value);

	friend istream& operator>>(istream& in, Pair& other);
	friend ostream& operator << (ostream& out, const Pair& other);

	friend fstream& operator >> (fstream& fin, Pair& p);
	friend fstream& operator << (fstream& fout, const Pair& p);
};