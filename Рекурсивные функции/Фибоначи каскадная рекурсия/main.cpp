#include <iostream>
#include <clocale>
using namespace std;

int fib(int n)
{	
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 2) + fib(n - 1);

}

int main()
{
	setlocale(LC_ALL, "Russian");
	int k;
	cout << "Введите количество чисел последовательности Фибоначи: ";
	cin >> k;
	if (k > 0)
	{
		for (int i = 0; i < k; i++)
			cout << fib(i) << ' ';
	}
	else
		cout << "Введено неверное количество чисел";
	return 0;
}

