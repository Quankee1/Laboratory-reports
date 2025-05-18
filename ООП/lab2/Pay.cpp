#include "Pay.h"
using namespace std;

Pay::Pay() : fio("None"),  prize(0)
{
	cout << "Вызов конструктора без параметров..." << endl;
	salary = new double(0);
};

Pay::Pay(string m_fio, double m_salary, int m_prize) : fio(m_fio), prize(m_prize) 
{
	cout << "Вызов конструктора с параметрами..." << endl;
	salary = new double(m_salary);
};

Pay::Pay(const Pay& other) : fio(other.fio), prize(other.prize)
{
	cout << "Вызов конструктора копирования..." << endl;
	salary = new double(*other.salary);
}; 

Pay::~Pay()
{
	cout << "Вызов деструктора..." << endl;
	delete salary;
} 

void Pay::set_data(string fio, double salary, int prize)
{
	cout << "Вызов метода set_data..." << endl;
	this->fio = fio;
	this->salary = new double(salary);
	this->prize = prize;
}

string Pay::get_fio() { return fio; };
double Pay::get_salary() { return *salary; };
int Pay::get_prize() { return prize; };