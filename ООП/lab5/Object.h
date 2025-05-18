#pragma once
#include <iostream>
using namespace std;

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;
	virtual void Show() = 0;
};