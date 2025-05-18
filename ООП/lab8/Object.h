#pragma once
#include <iostream>
using namespace std;

class Object 
{
public:
    virtual ~Object() = default;
    virtual void Show() = 0;
    virtual void HandleEvent(const struct TEvent& e) = 0;
};