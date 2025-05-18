#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
	T data;
};