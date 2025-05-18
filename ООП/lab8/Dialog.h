#pragma once
#include "Vector.h"
#include "Event.h"
#include "PRINT.h"
#include "MAGAZIN.h"
#include <string>
#include <iostream>
using namespace std;

class Dialog : public Vector 
{
protected:
    int EndState;
    void AddObject();
public:
    Dialog() : Vector(), EndState(0) {}
    virtual ~Dialog() = default;

    void GetEvent(TEvent&);
    int Execute();
    void HandleEvent(TEvent&);
    void ClearEvent(TEvent&);
    int Valid();
    void EndExec();
};

void Dialog::GetEvent(TEvent& event) 
{
    string OpInt = "+-szqm";  
    string s;
    char code;

    cout << ">";
    cin >> s;
    code = s[0];

    if (OpInt.find(code) != string::npos) 
    {
        event.what = evMessage;
        switch (code) 
        {
        case 'm': event.command = cmMake; break;
        case '+': event.command = cmAdd; break;
        case '-': event.command = cmDel; break;
        case 's': event.command = cmShow; break;
        case 'z': event.command = cmGet; break;
        case 'q': event.command = cmQuit; break;
        }

        if (s.length() > 1) 
        {
            string param = s.substr(1);
            event.a = stoi(param);
        }
    }
    else 
    {
        event.what = evNothing;
    }
}

int Dialog::Execute() 
{
    TEvent event;
    do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);
        if (event.what != evNothing && event.command != cmQuit) 
        {
            cout << "\nUnknown command";
        }
    } while (!Valid());
    return EndState;
}

void Dialog::HandleEvent(TEvent& event) 
{
    if (event.what == evMessage) 
    {
        switch (event.command) 
        {
        case cmMake:
            size = event.a;
            beg = new Object * [size];
            cur = 0;
            ClearEvent(event);
            break;
        case cmAdd:
            AddObject();
            ClearEvent(event);
            break;
        case cmDel:
            if (cur > 0) 
            {
                delete beg[--cur];
            }
            ClearEvent(event);
            break;
        case cmShow:
            Show();
            ClearEvent(event);
            break;
        case cmGet:
            Vector::HandleEvent(event);
            ClearEvent(event);
            break;
        case cmQuit:
            EndExec();
            ClearEvent(event);
            break;
        }
    }
}

void Dialog::AddObject() 
{
    cout << "\n1. PRINT\n2. MAGAZIN\nChoice: ";
    int choice;
    cin >> choice;

    Object* p = nullptr;
    if (choice == 1) 
    {
        string title, author;
        cout << "\nTitle: "; cin >> title;
        cout << "\nAuthor: "; cin >> author;
        p = new PRINT(title, author);
    }
    else if (choice == 2) 
    {
        string title, author;
        int pages;
        cout << "\nTitle: "; cin >> title;
        cout << "\nAuthor: "; cin >> author;
        cout << "\nPages: "; cin >> pages;
        p = new MAGAZIN(title, author, pages);
    }

    if (p != nullptr) 
    {
        Add(p);
    }
}

void Dialog::ClearEvent(TEvent& event) 
{
    event.what = evNothing;
}

int Dialog::Valid() 
{
    return EndState;
}

void Dialog::EndExec() 
{
    EndState = 1;
}