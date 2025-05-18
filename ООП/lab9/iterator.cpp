#include <iostream>
#include  "Iterator.h"
#include  "Node.h"
#include "List.h"
using namespace std;

Iterator::Iterator() : elem(nullptr) {};
Iterator::Iterator(const Iterator& other) : elem(other.elem) {};
Iterator Iterator::operator++(int)
{
	if (elem == nullptr) throw 7;
	elem = elem->next;
	return *this;
}

Iterator Iterator::operator--(int)
{
	if (elem == nullptr) throw 7;
	elem = elem->prev;
	return *this;
}

Iterator Iterator::operator+(int n)
{
	Iterator temp = *this;
	for (int i = 0; i < n; i++)
	{
		if (temp.elem == nullptr) throw 9;
		elem = elem->next;
	}
	return *this;
}
Iterator Iterator::operator-(int n)
{
	Iterator temp = *this;
	for (int i = 0; i < n; i++)
	{
		if (temp.elem == nullptr) throw 9;
		elem = elem->prev;
	}
	return *this;
}

int& Iterator::operator*()
{
	if (elem == nullptr) throw 8;
	return elem->data;
}

bool Iterator::operator==(const Iterator& other)
{
	return elem == other.elem;
}

bool Iterator::operator!=(const Iterator& other)
{
	return elem != other.elem;
}