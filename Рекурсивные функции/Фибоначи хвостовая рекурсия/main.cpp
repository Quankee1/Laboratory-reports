#include <iostream>
#include <clocale>
using namespace std;

int fib(int n, int a = 0, int b = 1)
{
	if (n == 0)
		return b;
	return fib(n - 1, b, a + b);
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