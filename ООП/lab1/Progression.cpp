#include <iostream>
#include "Progression.h"
using namespace std;

void Progression::Init(double F, unsigned int S)
{
	first = F;
	second = S;
}

void Progression::Read()
{
	cout << "fist?" << endl;
	cin >> first;
	cout << "second?" << endl;
	cin >> second;
}

void Progression::Show()
{
	cout << "fist = " << first << endl;
	cout << "second = " << second << endl << endl;

}

double Progression::element(int j)
{
	double res = first * pow(second, j);
	return res;
}