#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() : name{ "None" }, age(0) {};
Person::Person(string n, int a) : name{ n }, age(a) {};
Person::Person(const Person& other) : name{ other.name }, age(other.age) {};
Person:: ~Person() {};

string Person::get_name() { return name; };
int Person::get_age() { return age; };

void Person::set_name(string name) { this->name = name; };
void Person::set_age(int age) { this->age = age; };

Person& Person::operator = (const Person& other)
{
	if (this == &other) { return *this; }
	name = other.name;
	age = other.age;
	return *this;
}

istream& operator >> (istream& in, Person& other)
{
	cout << "\nName: ";
	in >> other.name;
	cout << "\nAge: ";
	in >> other.age;
	return in;
}

ostream& operator << (ostream& out, const Person& other)
{
	out << "\nName: " << other.name;
	out << "\nAge: " << other.age;
	return out;
}

void Person::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << '\n';
}