#pragma once
#include "PRINT.h"
#include <iostream>
using namespace std;

class MAGAZIN : public PRINT 
{
protected:
    int pages;
public:
    MAGAZIN() : PRINT(), pages(0) {}
    MAGAZIN(string t, string a, int p) : PRINT(t, a), pages(p) {}
    MAGAZIN(const MAGAZIN& other) : PRINT(other), pages(other.pages) {}

    int get_pages() const { return pages; }
    void set_pages(int p) { pages = p; }

    void Show() override
    {
        PRINT::Show();
        cout << "Pages: " << pages << endl;
    }

    friend ostream& operator<<(ostream& os, const MAGAZIN& m) 
    {
        os << (PRINT)m << "\nPages: " << m.pages;
        return os;
    }
};