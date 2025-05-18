#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m, s;
	cout << "Введите размерность: ";
	cin >> n >> m;
	cout << "Введите по какой строке сортировать ";
	cin >> s;
	s--;
	int** ptr = new int* [n];
	for (int i = 0; i < n; i++)
		ptr[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ptr[i][j] = rand() % 20;

	cout << "Изначальный массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << ptr[i][j] << '\t';
		cout << endl;
	}
	cout << endl;

	// Соритровка выбором
	for (int i = 0; i < m; i++)
	{
		int min = i;
		for (int j = i + 1; j < m; j++)
		{
			if (ptr[s][j] < ptr[s][min])
				min = j;
		}
		for (int k = 0; k < n; k++)
		{
			int temp = ptr[k][min];
			ptr[k][min] = ptr[k][i];
			ptr[k][i] = temp;
		}
	}
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << ptr[i][j] << '\t';
		cout << endl;
	}


	for (int i = 0; i < n; i++)
		delete[] ptr[i];
	delete[] ptr;

}