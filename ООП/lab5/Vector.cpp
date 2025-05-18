#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector() : beg(nullptr), size(0), cur(0) {};
Vector::Vector(int n)
{
	beg = new Object* [n];
	cur = 0;
	size = n;
}
Vector::~Vector()
{
	if (beg != nullptr) 
	{
		for (int i = 0; i < cur; i++) 
		{
			delete beg[i];
		}
		delete[] beg;
	}
}

void Vector::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

ostream& operator << (ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty" << endl;
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show();
		p++;
	}
	return out;
}