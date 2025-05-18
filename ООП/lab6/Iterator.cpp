#include <iostream>
#include  "Iterator.h"
#include  "Node.h"
#include "List.h"
using namespace std;

Iterator::Iterator() : elem(nullptr) {};
Iterator::Iterator(const Iterator& other) : elem(other.elem) {};
Iterator Iterator::operator++(int)
{
	elem = elem->next;
	return *this;
}

Iterator Iterator::operator--(int)
{
	elem = elem->prev;
	return *this;
}

Iterator Iterator::operator+(int n)
{
	for (int i = 0; i < n; i++)
	{
		elem = elem->next;
	}
	return *this;
}
Iterator Iterator::operator-(int n)
{
	for (int i = 0; i < n; i++)
	{
		elem = elem->prev;
	}
	return *this;
}

int& Iterator::operator*()
{
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