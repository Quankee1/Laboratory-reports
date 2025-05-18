#include <iostream>
#include  "Iterator.h"
#include  "Node.h"
#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	List list1(3, 5);  // ������ �� 3 ���������: [5, 10, 20]
	List list2(4, 2);  // ������ �� 4 ���������: [2, 10, 20, 30]

	cout << "List 1: " << list1 << endl;
	cout << "List 2: " << list2 << endl;

	cout << "�������� [] - ������ �� �������:" << endl;
	cout << "list1[0] = " << list1[0] << endl;
	cout << "list1[1] = " << list1[1] << endl;
	cout << "list2[3] = " << list2[3] << endl << endl;

	cout << "�������� int() - ������ ������:" << endl;
	cout << "������ list1: " << list1() << endl;
	cout << "������ list2: " << list2() << endl << endl;

	cout << "�������� * - ��������� �������:" << endl;
	List result = list1 * list2;
	cout << "��������� ���������: " << result << endl << endl;

	cout << "�������� +n - ������ � ����������:" << endl;
	Iterator it = list1.first();
	cout << "������ �������: " << *it << endl;
	it = it + 2;
	cout << "����� it + 2: " << *it << endl << endl;

	cout << "���������������� ����� list2:" << endl;
	for (Iterator it2 = list2.first(); it2 != list2.last(); it2++) 
	{
		cout << *it2 << " ";
	}
	cout << endl;

	return 0;
}

