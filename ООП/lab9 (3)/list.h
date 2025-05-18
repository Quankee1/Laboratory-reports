#pragma once
#include <iostream>
#include "Node.h"
#include "Iterator.h"
#include "error.h"
using namespace std;

class List
{
	int size;
	Node* head = nullptr;
	Node* tail = nullptr;
	Iterator beg;
	Iterator end;
public:
	List(int, int);
	List(const List&);
	~List();
	int front();
	int back();
	void pushback(int);
	void pushfront(int);
	void popback();
	void popfront();
	List& operator=(List&);
	int operator()();
	int& operator[](int);
	List operator*(List&);
	Iterator first();
	Iterator last();

	friend ostream& operator<<(ostream&, List&);
	friend istream& operator>>(istream&, List&);
};