#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public  Person
{
protected:
	string subject;
	int mark;

public:
	Student();
	Student(string, int, string, int);
	Student(const Student&);
	~Student();

	string get_name();
	int get_age();

	void set_name(string);
	void set_age(int);

	Student& operator = (const Student&);
	friend istream& operator >> (istream&, Student&);
	friend ostream& operator << (ostream&, const Student&);

	bool bad_mark() const;
};