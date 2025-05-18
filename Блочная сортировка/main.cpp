#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int a[], int n) 
{
    // Создаем массив блоков
    int buckets[10][10];
    int size[10] = { 0 };

    // Распределяем числа по блокам
    for (int i = 0; i < n; i++)
    {
        int t = a[i];
        int c = 0;
        while (t > 0)
        {
            t /= 10;
            c++;
        }
        int idx = c - 1; // Индекс блока (по количеству цифр в числе)

        buckets[idx][size[idx]++] = a[i];
    }

    // Вывод содержимого блоков после распределения
    cout << "Блоки после распределения:" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (size[i] > 0)
        {
            cout << "Блок " << i + 1 << " (числа с " << i + 1 << " цифрой): ";
            for (int j = 0; j < size[i]; j++)
            {
                cout << buckets[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    // Сортировка каждого блока и вывод отсортированных блоков
    cout << "Блоки после сортировки:" << endl;
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        if (size[i] > 0)
        {
            insertionSort(buckets[i], size[i]);
            cout << "Блок " << i + 1 << " (отсортированный): ";
            for (int j = 0; j < size[i]; j++)
            {
                cout << buckets[i][j] << " ";
                a[index++] = buckets[i][j];
            }
            cout << endl;
        }
    }
    cout << endl;
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a[] = { 170, 45, 75, 90, 802, 24, 2, 66, 1 };
    const int n = 9;

    cout << "Исходный массив: ";
    print(a, n);

    bucketSort(a, n);

    cout << "Отсортированный массив: ";
    print(a, n);

    return 0;
}