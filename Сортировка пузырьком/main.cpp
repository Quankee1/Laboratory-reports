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
		a[i] = rand() % 100;
	}

	cout << "Изначальный массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << ' ';
		}
		cout << endl;
		
	}
	cout << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}


	return 0;
}