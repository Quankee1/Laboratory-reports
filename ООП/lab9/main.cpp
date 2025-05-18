#include "list.h"
#include "iterator.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		List x(2, 1);
		List y(1, 1);
		cout << x;
		cout << "Nomer? ";
		int i;
		cin >> i;
		cout << x[i] << endl;
		y.pushback(3);
		cout << y;
		x.popback(); cout << x;
		x.popback();  cout << x;
		x.popback();
		x.front();
	}
	catch (int errorCode)
	{
		switch (errorCode) 
		{
		case 1:  cout << "Ошибка: превышен максимальный размер списка (MAX_SIZE = 30)" << endl; break;
		case 2:  cout << "Ошибка: недопустимый индекс (выход за границы списка)" << endl; break;
		case 4:  cout << "Ошибка: невозможно добавить элемент - список полон" << endl; break;
		case 5:  cout << "Ошибка: попытка удаления из пустого списка" << endl; break;
		case 6:  cout << "Ошибка: обращение к элементу пустого списка (front/back)" << endl; break;
		case 7:  cout << "Ошибка итератора: недопустимая операция (++/--) для end-итератора" << endl; break;
		case 8:  cout << "Ошибка итератора: разыменование нулевого итератора" << endl; break;
		case 9:  cout << "Ошибка итератора: выход за границы при арифметике итераторов" << endl; break;
		default: cout << "Неизвестная ошибка (код: " << errorCode << ")" << endl;
		}
	}

	return 0;

}