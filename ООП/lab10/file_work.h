#pragma once
#include "Pair.h"
#include <iostream>
#include <fstream>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	int n;
	Pair p;
	cout << "N? "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << "\n";
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
    fstream stream(f_name, ios::in);
   
    Pair p;
    int i = 0;

    while (stream >> p)
    {
        cout << p << "\n";
        i++;
    }

    stream.close();
    return i;
}

// Добавьте в file_work.h
int del(const char* f_name, const Pair& other)
{
    fstream temp("temp", ios::out);  
    fstream stream(f_name, ios::in);

    Pair p;
    int count = 0; 

    while (stream >> p) 
    {

        if (!(p.get_first() < other.get_first() &&
            p.get_second() < other.get_second())) 
        {
            temp << p;
        }
        else 
        {
            count++; 
        }
    }

    stream.close();
    temp.close();

    remove(f_name);         
    rename("temp", f_name); 

    return count; 
}

int increase(const char* f_name, const Pair& target, int L_int, double L_double)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);

    Pair p;
    int count = 0; 

    while (stream >> p)
    {
        if (p.get_first() == target.get_first() &&
            p.get_second() == target.get_second())
        {

            p += L_int;   
            p += L_double; 
            count++;
        }
        temp << p; 
    }

    stream.close();
    temp.close();

    remove(f_name);
    rename("temp", f_name);

    return count; 
}

int insert_after_position(const char* f_name, int position, int K)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);

    Pair p;
    int current_pos = 0;
    int inserted_count = 0;

    while (stream >> p && current_pos <= position)
    {
        temp << p;
        current_pos++;
    }


    if (current_pos > position) 
    {
        for (int i = 0; i < K; i++)
        {
            Pair new_pair;
            cout << "Enter new pair " << i + 1 << " (int double): ";
            cin >> new_pair;
            temp << new_pair;
            inserted_count++;
        }
    }
    while (stream >> p)
    {
        temp << p;
    }

    stream.close();
    temp.close();

    remove(f_name);
    rename("temp", f_name);

    return inserted_count;
}