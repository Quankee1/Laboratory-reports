#include "Pair.h"
using namespace std;

Pair::Pair() : first(0), second(0) {};
Pair::Pair(int f, double s) : first(f), second(s) {};
Pair::Pair(const Pair& other) : first(other.first), second(other.second) {};
Pair::~Pair() {};
void Pair::set_data(int f, double s)
{
	first = f;
	second = s;
}

int Pair::get_first() { return first; };

Pair& Pair::operator = (const Pair& other)
{
	if (&other == this) { return *this; }
	first = other.first;
	second = other.second;
	return *this;
}

Pair Pair::operator-(const Pair& other)
{
	Pair result;
	result.first = this->first - other.first;
	result.second = this->second - other.second;
	return result;
}

Pair& Pair::operator+=(int value)
{
	first += value;
	return *this;
}

Pair& Pair::operator+=(double value) 
{
	second += value;
	return *this;
}


istream& operator >> (istream& in, Pair& other)
{
	cout << "first?";
	in >> other.first;
	cout << "second?";
	in >> other.second;
	return in;
}

ostream& operator << (ostream& out, const Pair& other)
{
	return (out << other.first << " : " << other.second);
}