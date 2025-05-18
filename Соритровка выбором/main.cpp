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
	{
		a[i] = rand() % 250;
	}

	cout << "Изначальный массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << ' ';
		}
		cout << endl;
	}
	cout << endl << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}

	return 0;
}