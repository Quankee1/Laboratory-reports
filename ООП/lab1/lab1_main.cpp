#include <iostream>
#include "Progression.h"
using namespace std;

Progression make_Progression(double F, int S)
{
	Progression t;
	t.Init(F, S);
	return t;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Progression A;
	Progression B;
	A.Init(3.0, 2);
	B.Read();
	A.Show();
	B.Show();

	int j;
	cout << "¬ведите j: ";
	cin >> j;
	cout << A.element(j) << endl << B.element(j) << endl;

	Progression* X = new Progression;

	X->Init(2.0, 5);
	X->Show();
	cout << X->element(j) << endl;

	Progression arr[3];

	for (int i = 0; i < 3; i++)
		arr[i].Read();

	for (int i = 0; i < 3; i++)
		arr[i].Show();

	for (int i = 0; i < 3; i++)
		cout << "#" << i << ' ' << arr[i].element(j) << endl;

	Progression* p_arr = new Progression[3];

	for (int i = 0; i < 3; i++)
		p_arr[i].Read();

	for (int i = 0; i < 3; i++)
		p_arr[i].Show();

	for (int i = 0; i < 3; i++)
		cout << "#" << i << ' ' << p_arr[i].element(j) << endl;

	double y; 
	unsigned int z;
	cout << "fist?" << endl;
	cin >> y;
	cout << "second?" << endl;
	cin >> z;

	Progression f = make_Progression(y, z);
	f.Show();

	return 0;
}