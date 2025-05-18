#include <iostream>
#include <clocale>
using namespace std;

// Функция для удаления четных строк
void Remove(int a[][4], int& row, int column)
{
    int new_row = 0;
    for (int i = 0; i < row; i++)
        if (i % 2 == 0)
        {
           for (int j = 0; j < column; j++)
           {
               a[new_row][j] = a[i][j];
           }
           new_row++;
        }
    row = new_row;
}

void Remove(double a[][3], int& row, int column)
{
    int new_row = 0;
    for (int i = 0; i < row; i++)
        if (i % 2 == 0)
        {
            for (int j = 0; j < column; j++)
            {
                a[new_row][j] = a[i][j];
            }
            new_row++;
        }
    row = new_row;
}

// Функция для вывода массива
void Print(int a[][4], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }   
}

void Print(double a[][3], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

int main()

{
	setlocale(LC_ALL, "Russian");

    int intA[4][4] = {
        {11, 22, 33, 44},
        {55, 66, 77, 88},
        {99, 100, 111, 122},
        {133, 144, 155, 166}
    };

    double doubleA[3][3] = {
        {1.1, 2.2, 3.3},
        {5.5, 6.6, 7.7},
        {9.9, 10.1, 11.2},
    };

    int row_int = 4, column_int = 4;
    int row_double = 3, column_double = 3;

    cout << "Изначальный двумерный массив (int):" << endl;
    Print(intA, row_int, column_int);

    cout << "Измененный двумерный массив (int):" << endl;
    Remove(intA, row_int, column_int);
    Print(intA, row_int, column_int);

    cout << "Изначальный двумерный массив (double):" << endl;
    Print(doubleA, row_double, column_double);

    cout << "Измененный двумерный массив (double):" << endl;
    Remove(doubleA, row_double, column_double);
    Print(doubleA, row_double, column_double);

    return 0;
}