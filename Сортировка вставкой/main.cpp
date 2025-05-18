#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	const int n = 10;
	int a[n];

	for (int i = 0; i < n; i++)
		a[i] = rand() % 25;

	cout << "Изначальный массив: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
	for (int i = 1; i < n; i++) 
	{
		int t = a[i];
		int j = i - 1;

		while (j >= 0 && a[j] > t) 
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	
	cout << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';

	return 0;
}