#pragma once
#include <iostream>
using namespace std;

class Pay
{
	 string fio;
	 double* salary;
	 int prize;

public:
	Pay();
	Pay(string, double, int);
	Pay(const Pay&);
	~Pay();

	void set_data(string, double, int);
	string get_fio();
	double get_salary();
	int get_prize();

	friend void print(Pay& obj);
};