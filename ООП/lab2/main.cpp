#include "Pay.h"
using namespace std;

void print(Pay& obj)
{
	cout << "�������� ����� �������: " << endl;
	cout << "fio = " << obj.get_fio() << endl;
	cout << "salary = " << obj.get_salary() << endl;
	cout << "prize = " << obj.get_prize() << endl << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	Pay obj1; // ����� ������������ ��� ����������
	print(obj1);

	Pay obj2("������� ���� �����������", 100, 10); // ����� ������������ � �����������
	print(obj2);

	Pay obj3(obj2); // ����� ������������ �����������
	print(obj3);

	// ������ �������� ����� � ������� ������ set_data
	obj3.set_data("������ ���� ��������", 52, 49);
	print(obj3);
}