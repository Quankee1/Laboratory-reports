#include <iostream>
using namespace std;

void countingSort(int arr[], int n)
{
    int minVal = arr[0];
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int range = maxVal - minVal + 1;

    int* count = new int[range]();

    cout << "Подсчет элементов: ";
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - minVal]++;
        cout << arr[i] << " ";
    }
    cout << endl;

    int index = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            arr[index] = i + minVal;
            index++;
            count[i]--;
            cout << "Шаг сортировки: ";
            for (int j = 0; j < n; j++)
                cout << arr[j] << " ";
            cout << endl;
        }
    }

    delete[] count;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr[] = { 4, -2, 2, 8, 3, 3, -1, -5, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    print(arr, n);

    countingSort(arr, n);

    cout << "Отсортированный массив: ";
    print(arr, n);

    return 0;
}