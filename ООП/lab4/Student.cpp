#include "Person.h"
#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : Person(), subject("None"), mark(0) {};
Student::Student(string n, int a, string s, int m) : Person(n, a)
{
	subject = s;
	mark = m;
}
Student::Student(const Student& other)
{
	name = other.name;
	age = other.age;
	subject = other.subject;
	mark = other.mark;
}
Student::~Student() {};
string Student::get_name() { return name; }
int Student::get_age() { return age; }
void Student::set_name(string n) { name = n; }
void Student::set_age(int a) { age = a; }
Student& Student::operator = (const Student& other)
{
	if (this == &other) { return *this; }
	name = other.name;
	age = other.age;
	subject = other.subject;
	mark = other.mark;
	return *this;
}
bool Student::bad_mark() const
{
	if (mark == 2) { return true; }
	else { return false; }
}

istream& operator >> (istream& in, Student& other)
{
	cout << "\nName: "; in >> other.name;
	cout << "\nAge: "; in >> other.age; 
	cout << "\nSubject: "; in >> other.subject;
	cout << "\nMark: "; in >> other.mark;
	return in;
}
ostream& operator << (ostream& out, const Student& other)
{
	out << "\nName: "; out << other.name;
	out << "\nAge: "; out << other.age;
	out << "\nSubject: "; out << other.subject;
	out << "\nMark: "; out << other.mark;
	if (other.bad_mark()) {
		out << "\nBad mark!";
	}
	return out;
}

