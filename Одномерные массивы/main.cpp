#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubble_sort(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (a[j - 1] < a[j])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	cout << "Элементы упорядочены по убыванию!" << endl;
} 

void del_el(int a[], int &N)
{
	int j = 0; 

	for (int i = 0; i < N; i++)
	{
		if (a[i] % 2 == 0) 
		{
			a[j] = a[i];
			j++;
		}
	}

	for (int i = j; i < N; i++) 
		a[i] = 0;  
	N = j;
}

void ring(int a[], int N, int index)
{
	cout << "\nОднонаправленное кольцо (движение вправо):" << endl;
	for (int i = 0; i < N; i++)
		cout << a[(index + i) % N] << " ";
	cout << "\nОднонаправленное кольцо (движение влево):" << endl;
	for (int i = 0; i < N; i++)
		cout << a[(index - i + N) % N] << " ";
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	const int n = 100;
	int user;
	int a[n];
	int N;
	cout << "Введите длину массива (max 100): ";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 25;
	}
	cout << "Исходный массив: " << endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << ' ';

	do {
		cout << "\n\n1. Вывести массив" << endl;
		cout << "2. Вывести одномерное кольцо" << endl;
		cout << "3. Удалить нечетные элементы" << endl;
		cout << "4. Упорядочить элементы по убыванию" << endl;
		cout << "5. Выход" << endl;
		cout << "Выберите действие: ";
		cin >> user;
		switch (user)
		{
		case 1:
			for (int i = 0; i < N; i++)
				cout << a[i] << ' ';

			cout << endl;
			break;
		case 2: 
			int index;
			do 
			{
				cout << "Введите с какого индекса начинать вывод: ";
				cin >> index;
				if (index < 0 || index > N - 1)
					cout << "Неверный индекс!" << endl;
			} while (index < 0 || index > N - 1);
			ring(a, N, index);
			break;
		case 3: 
			del_el(a, N);
			cout << "Элементы удалены!" << endl;
			break;
		case 4: 
			bubble_sort(a, N);
			break;
		case 5: cout << "Выход...";
			break;
		default: cout << "Неверный выбор! Попробуйте снова";
			break;
		}
	} while (user != 5);

}