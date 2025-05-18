#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubble_sort(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (a[j - 1] < a[j])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	cout << "�������� ����������� �� ��������!" << endl;
} 

void del_el(int a[], int &N)
{
	int j = 0; 

	for (int i = 0; i < N; i++)
	{
		if (a[i] % 2 == 0) 
		{
			a[j] = a[i];
			j++;
		}
	}

	for (int i = j; i < N; i++) 
		a[i] = 0;  
	N = j;
}

void ring(int a[], int N, int index)
{
	cout << "\n���������������� ������ (�������� ������):" << endl;
	for (int i = 0; i < N; i++)
		cout << a[(index + i) % N] << " ";
	cout << "\n���������������� ������ (�������� �����):" << endl;
	for (int i = 0; i < N; i++)
		cout << a[(index - i + N) % N] << " ";
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	const int n = 100;
	int user;
	int a[n];
	int N;
	cout << "������� ����� ������� (max 100): ";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 25;
	}
	cout << "�������� ������: " << endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << ' ';

	do {
		cout << "\n\n1. ������� ������" << endl;
		cout << "2. ������� ���������� ������" << endl;
		cout << "3. ������� �������� ��������" << endl;
		cout << "4. ����������� �������� �� ��������" << endl;
		cout << "5. �����" << endl;
		cout << "�������� ��������: ";
		cin >> user;
		switch (user)
		{
		case 1:
			for (int i = 0; i < N; i++)
				cout << a[i] << ' ';

			cout << endl;
			break;
		case 2: 
			int index;
			do 
			{
				cout << "������� � ������ ������� �������� �����: ";
				cin >> index;
				if (index < 0 || index > N - 1)
					cout << "�������� ������!" << endl;
			} while (index < 0 || index > N - 1);
			ring(a, N, index);
			break;
		case 3: 
			del_el(a, N);
			cout << "�������� �������!" << endl;
			break;
		case 4: 
			bubble_sort(a, N);
			break;
		case 5: cout << "�����...";
			break;
		default: cout << "�������� �����! ���������� �����";
			break;
		}
	} while (user != 5);

}