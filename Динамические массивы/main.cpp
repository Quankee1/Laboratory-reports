#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251 > NULL");

	// Размер массива
	int n = 0;
	while (n <= 0)
	{
		cout << "Введите размер массива: ";
		cin >> n;
		if (n <= 0)
			cout << "Размер массива не может быть <= 0" << endl;
	}

	// Массив с помощью операции new
	string* a = new string[n];
	// Заполнение массива
	cout << "Введите строки для массива:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Строка " << i + 1 << ": ";
		cin >> a[i];
	}

	cout << "Текущий массив строк: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	// Позиция, куда нужно вставить новую строку
	int position = 0;
	while (position < 1 || position > n + 1)
	{
		cout << "Введите номер, куда нужно вставить новую строку(от 1 до " << n + 1 << ") : ";
		cin >> position;
		if (position < 1 || position > n + 1)
			cout << "Номер может быть от 1 до " << n + 1 << endl;
	}

	// Вводим новую строку
	string new_string;
	cout << "Введите новую строку: ";
	cin >> new_string;

	// Новый массив
	string* new_a = new string[n + 1];
	for (int i = 0, j = 0; i < n + 1; i++)
	{
		if (i == position - 1)
			new_a[i] = new_string;
		else
			new_a[i] = a[j++];
	}

	// Вывод
	cout << "После вставки строки : ";
	for (int i = 0; i < n + 1; i++)
		cout << new_a[i] << ' ';
	
	delete[] a;
	delete[] new_a;
	a = nullptr;
	new_a = nullptr;

	return 0;

}