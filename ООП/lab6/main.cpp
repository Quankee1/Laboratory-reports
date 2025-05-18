#include <iostream>
#include  "Iterator.h"
#include  "Node.h"
#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	List list1(3, 5);  // Список из 3 элементов: [5, 10, 20]
	List list2(4, 2);  // Список из 4 элементов: [2, 10, 20, 30]

	cout << "List 1: " << list1 << endl;
	cout << "List 2: " << list2 << endl;

	cout << "Операция [] - доступ по индексу:" << endl;
	cout << "list1[0] = " << list1[0] << endl;
	cout << "list1[1] = " << list1[1] << endl;
	cout << "list2[3] = " << list2[3] << endl << endl;

	cout << "Операция int() - размер списка:" << endl;
	cout << "Размер list1: " << list1() << endl;
	cout << "Размер list2: " << list2() << endl << endl;

	cout << "Операция * - умножение списков:" << endl;
	List result = list1 * list2;
	cout << "Результат умножения: " << result << endl << endl;

	cout << "Операция +n - работа с итератором:" << endl;
	Iterator it = list1.first();
	cout << "Первый элемент: " << *it << endl;
	it = it + 2;
	cout << "После it + 2: " << *it << endl << endl;

	cout << "Последовательный обход list2:" << endl;
	for (Iterator it2 = list2.first(); it2 != list2.last(); it2++) 
	{
		cout << *it2 << " ";
	}
	cout << endl;

	return 0;
}

