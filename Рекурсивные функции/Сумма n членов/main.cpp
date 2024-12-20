#include <iostream>
#include <clocale>
using namespace std;

double S(double x, int n)
{
	double f;
	
	int factorial = (2 * n + 1);

	for (int i = 1; i < (2 * n + 1); i++)
		factorial *= i;

	f = pow(x, 2 * n + 1) / factorial;

	if (n == 0)
		return x;
	
	return f + S(x, n - 1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	double x;

	cout << "Введите количество членов ряда: ";
	cin >> n;

	cout << "Введите \"x\": ";
	cin >> x;

	if (n > 0)
		cout << "Итоговая сумма: " << S(x, n);
	else
		cout << "Введено неверное количество";

	return 0;
}