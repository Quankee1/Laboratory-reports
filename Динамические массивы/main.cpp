#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251 > NULL");

	// ������ �������
	int n = 0;
	while (n <= 0)
	{
		cout << "������� ������ �������: ";
		cin >> n;
		if (n <= 0)
			cout << "������ ������� �� ����� ���� <= 0" << endl;
	}

	// ������ � ������� �������� new
	string* a = new string[n];
	// ���������� �������
	cout << "������� ������ ��� �������:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "������ " << i + 1 << ": ";
		cin >> a[i];
	}

	cout << "������� ������ �����: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	// �������, ���� ����� �������� ����� ������
	int position = 0;
	while (position < 1 || position > n + 1)
	{
		cout << "������� �����, ���� ����� �������� ����� ������(�� 1 �� " << n + 1 << ") : ";
		cin >> position;
		if (position < 1 || position > n + 1)
			cout << "����� ����� ���� �� 1 �� " << n + 1 << endl;
	}

	// ������ ����� ������
	string new_string;
	cout << "������� ����� ������: ";
	cin >> new_string;

	// ����� ������
	string* new_a = new string[n + 1];
	for (int i = 0, j = 0; i < n + 1; i++)
	{
		if (i == position - 1)
			new_a[i] = new_string;
		else
			new_a[i] = a[j++];
	}

	// �����
	cout << "����� ������� ������ : ";
	for (int i = 0; i < n + 1; i++)
		cout << new_a[i] << ' ';
	
	delete[] a;
	delete[] new_a;
	a = nullptr;
	new_a = nullptr;

	return 0;

}