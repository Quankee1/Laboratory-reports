#pragma once
#include "Object.h"
#include "Event.h"
#include <iostream>
using namespace std;

class PRINT : public Object 
{
protected:
    string title;
    string author;
public:
    PRINT() : title(""), author("") {}
    PRINT(string t, string a) : title(t), author(a) {}
    PRINT(const PRINT& other) : title(other.title), author(other.author) {}

    string get_title() const { return title; }
    string get_author() const { return author; }

    void set_title(string t) { title = t; }
    void set_author(string a) { author = a; }

    void Show() override 
    {
        cout << "Title: " << title << "\nAuthor: " << author << endl;
    }

    void HandleEvent(const struct TEvent& e) override 
    {
        if (e.what == evMessage)
        {
            switch (e.command) 
            {
            case cmGet:
                cout << "Title: " << title << endl;
                break;
            }
        }
    }

    friend ostream& operator<<(ostream& os, const PRINT& p) 
    {
        os << "Title: " << p.title << "\nAuthor: " << p.author;
        return os;
    }
};