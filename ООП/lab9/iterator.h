#pragma once
#include <iostream>
#include  "Node.h"
using namespace std;

class Iterator
{
	Node* elem;
public:
	Iterator();
	Iterator(const Iterator&);
	Iterator operator++(int);
	Iterator operator--(int);
	Iterator operator+(int);
	Iterator operator-(int);
	int& operator*();
	bool operator==(const Iterator&);
	bool operator!=(const Iterator&);
	friend class List;
};