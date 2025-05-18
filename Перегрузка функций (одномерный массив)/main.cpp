#include <iostream>
#include <clocale>
using namespace std;

void Remove(int a[], int& index)
{
	int temp[12]; 
	int tempIndex = 0; 

	for (int i = 0; i < index; i++)
	{
		// Если текущий и следующий (+2) элементы равны нулю, пропускаем элемент между ними
		if (a[i] == 0 && i + 2 < index && a[i + 2] == 0)
		{
			temp[tempIndex++] = a[i];   
			i++;                            
		}
		else
		{
			temp[tempIndex++] = a[i];   // Копируем обычный элемент
		}
	}

	// Обновляем индекс массива для дальнейшего правильного вывода массива
	index = tempIndex;

	// Копируем новый массив обратно в исходный
	for (int i = 0; i < index; i++)
	{
		a[i] = temp[i];
	}
}
void Remove(double a[], int& index)
{
	double temp[12]; 
	int tempIndex = 0; 
	for (int i = 0; i < index; i++)
	{
		// Если текущий и следующий (+2) элементы равны нулю, пропускаем элемент между ними
		if (a[i] == 0 && i + 2 < index && a[i + 2] == 0)
		{
			temp[tempIndex++] = a[i];   
			i++;                            
		}
		else
		{
			temp[tempIndex++] = a[i];   
		}
	}

	
	index = tempIndex;

	for (int i = 0; i < index; i++)
	{
		a[i] = temp[i];
	}
}


void Print(int a[], int index)
{
	for (int i = 0; i < index; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void Print(double a[], int index)
{
	for (int i = 0; i < index; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int int_A[12] = { 0, 0, 3, 4, 5, 0, 0, 6, 0, 0, 7, 0 };
	double double_A[9] = { 0.0, 1.1, 0.0, 2.2, 0.0, 1.3, 0.0, 0.0, 2.1};
	int index_int = 12, index_double = 9;

	cout << "Изначальный массив (int):" << endl;
	Print(int_A, index_int);

	cout << "Измененный массив (int):" << endl;
	Remove(int_A, index_int);
	Print(int_A, index_int);

	cout << "Изначальный массив (double):" << endl;
	Print(double_A, index_double);

	cout << "Измененный массив (double):" << endl;
	Remove(double_A, index_double);
	Print(double_A, index_double);
	
	return 0;
}