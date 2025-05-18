#include <iostream>
#include <chrono>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key) 
			return i;  
	}
	return -1;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 10000;  
	int arr[n];
	for (int i = 0; i < n; i++) 
		arr[i] = i * 2;  // ��������� ������ ������� �������
	

	int key;
	cout << "������� �������: ";
	cin >> key;

	auto start = chrono::high_resolution_clock::now(); // ����� �������

	int result = linearSearch(arr, n, key);

	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	auto duration_n = chrono::duration_cast<chrono::nanoseconds>(end - start);

	if (result >= 0)
		cout << "������� ������ �� �������: " << result << endl;

	else
		cout << "������� �� ������!" << endl;

	cout << "��������� ����������� �� " << duration.count() << " �����������." << endl;
	cout << "��������� ����������� �� " << duration_n.count() << " ����������." << endl;
}