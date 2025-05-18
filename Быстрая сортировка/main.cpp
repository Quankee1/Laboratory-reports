#include <iostream>
using namespace std;

void print(int arr[], int size, string message) 
{
    cout << message << ": ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int partition(int arr[], int low, int high, int pivot)
{
    int wall = low; // Индекс "стенки"

    for (int i = low; i <= high; i++)
    {
        if (arr[i] <= pivot) 
        {

            int temp = arr[wall];
            arr[wall] = arr[i];
            arr[i] = temp;

            wall++;
        }
    }

    wall--; 
    return wall;
}


void quickSort(int arr[], int low, int high, int size) 
{
    if (low < high) 
    {
        int pivot = arr[high];

        print(arr, size, "Текущий массив");
        cout << "Опорный элемент: " << pivot << endl;
        cout << "Диапазон: [" << low << ", " << high << "]" << endl;
        int new_pivot = partition(arr, low, high, pivot);

        cout << "После разделения: ";
        print(arr, size, "");
        cout << "----------------------------------------" << endl;

        quickSort(arr, low, new_pivot - 1, size);
        quickSort(arr, new_pivot + 1, high, size);
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int arr[6] = { 6, 3, 7, 1, 2, 5};
    int n = 6;

    cout << "Исходный массив: "; 
    print(arr, n, "");

    quickSort(arr, 0, n - 1, n);

    cout << "Отсортированный массив: ";
    print(arr, n, "");

    return 0;
}