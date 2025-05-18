#include <iostream>
#include  "Iterator.h"
#include  "Node.h"
#include "List.h"
using namespace std;

List::List(int s, int value)
{
	size = s;
	Node* newNode = new Node;
	newNode->data = value;
	head = newNode;
	tail = newNode;
	for (int i = 1; i < size; i++)
	{
		Node* newNode = new Node;
		newNode->data = i * 10;
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	tail->next = nullptr;
	beg.elem = head;
	end.elem = tail->next;
}

List::List(const List& other)
{
	Node* temp = other.head;
	while (temp != nullptr)
	{
		pushback(temp->data);
		temp = temp->next;
	}
	beg = other.beg;
	end = other.end;
}

List::~List()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* next = temp->next;
		delete temp;
		temp = next;
	}
	head = nullptr;
	tail = nullptr;
	size = 0;
}

int List::front()
{
	return head->data;
}

int List::back()
{
	return tail->data;
}

void List::pushback(int k)
{
	Node* newNode = new Node;
	newNode->data = k;
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		beg.elem = head;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	size++;
	end.elem = tail->next;
}

void List::pushfront(int k)
{
	Node* newNode = new Node;
	newNode->data = k;
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		beg.elem = head;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		beg.elem = head;
	}
	size++;
}

List& List::operator=(List& other)
{
	if (this == &other) return *this;

	Node* temp = head;
	while (temp != nullptr)
	{
		head = temp->next;
		delete temp;
		temp = head;
		size--;
	}

	Node* current = other.head;
	while (current != nullptr)
	{
		pushback(current->data);
		current = current->next;
	}
	beg = other.beg;
	end = other.end;
	return *this;
}

int List::operator()()
{
	return size;
}

int& List::operator[](int index)
{
	Node* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

List List::operator*(List& other)
{
	int new_size;
	if (size > other.size) new_size = other.size;
	else new_size = size;
	List new_List(new_size, 0);
	for (int i = 0; i < new_size; i++)
	{
		new_List[i] = (*this)[i] * other[i];
	}
	return new_List;
}

Iterator List::first()
{
	return beg;
}

Iterator List::last()
{
	return end;
}

istream& operator>>(istream& in, List& other)
{
	cout << "Elements?\n";
	Node* temp = other.head;
	while (temp != nullptr)
	{
		in >> temp->data;
		temp = temp->next;
	}
	return in;
}

ostream& operator<<(ostream& out, List& other)
{
	cout << "Ёлементы списка: ";
	Node* temp = other.head;
	while (temp != nullptr)
	{
		out << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return out;
}

void List::popback()
{
	Node* temp = tail;
	tail = temp->prev;
	tail->next = nullptr;
	delete temp;
	size--;
	end.elem = tail->next;
}

void List::popfront()
{
	Node* temp = head;
	head = temp->next;
	head->prev = nullptr;
	delete temp;
	size--;
	beg.elem = head;
}