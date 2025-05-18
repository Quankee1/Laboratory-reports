#include <iostream>
#include <chrono> 
using namespace std;

int binarySearch(int arr[], const int n, int key)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == key)
			return mid;

		else if (arr[mid] < key)
			left = mid + 1;

		else
		{
			right = mid - 1;
		}
	} 
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 10000;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = i * 2;  // Заполняем массив чётными числами

	int key;
	cout << "Введите элемент: ";
	cin >> key;

	auto start = chrono::high_resolution_clock::now(); // ЗАМЕР ВРЕМЕНИ

	int result = binarySearch(arr, n, key);

	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	auto duration_n = chrono::duration_cast<chrono::nanoseconds>(end - start);

	if (result >= 0) 
		cout << "Элемент найден на индексе: " << result << endl;

	else
		cout << "Элемент не найден!" << endl;

	cout << "Программа выполнилась за " << duration.count() << " микросекунд." << endl;
	cout << "Программа выполнилась за " << duration_n.count() << " наносекунд." << endl;
}