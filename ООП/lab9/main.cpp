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
		case 1:  cout << "������: �������� ������������ ������ ������ (MAX_SIZE = 30)" << endl; break;
		case 2:  cout << "������: ������������ ������ (����� �� ������� ������)" << endl; break;
		case 4:  cout << "������: ���������� �������� ������� - ������ �����" << endl; break;
		case 5:  cout << "������: ������� �������� �� ������� ������" << endl; break;
		case 6:  cout << "������: ��������� � �������� ������� ������ (front/back)" << endl; break;
		case 7:  cout << "������ ���������: ������������ �������� (++/--) ��� end-���������" << endl; break;
		case 8:  cout << "������ ���������: ������������� �������� ���������" << endl; break;
		case 9:  cout << "������ ���������: ����� �� ������� ��� ���������� ����������" << endl; break;
		default: cout << "����������� ������ (���: " << errorCode << ")" << endl;
		}
	}

	return 0;

}