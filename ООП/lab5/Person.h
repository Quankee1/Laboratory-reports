#pragma once
#include "Object.h"
#include <iostream>
using namespace std;
class Person : public Object
{
protected:
	string name;
	int age;

public:
	Person();
	Person(string, int);
	Person(const Person&);
	~Person();

	void Show();
	string get_name();
	int get_age();

	void set_name(string);
	void set_age(int);

	Person& operator = (const Person&);
	friend istream& operator >> (istream&, Person&);
	friend ostream& operator << (ostream&, const Person&);
};