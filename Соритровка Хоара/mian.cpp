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

int partition(int arr[], int low, int high)
{
    int pivot = arr[(low + high) / 2]; 
    int left = low - 1;  // Левая "стенка"
    int right = high + 1; // Правая "стенка"

    while (left < right)
    { 
        do {
            left++;
        } while (arr[left] < pivot);
     
        do {
            right--;
        } while (arr[right] > pivot);

        if (left < right) 
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    return right;
}

void quickSort(int arr[], int low, int high, int size) 
{
    if (low < high) 
    {
        print(arr, size, "Текущий массив");
        cout << "Опорный элемент: " << arr[(low + high) / 2] << endl;
        cout << "Диапазон: [" << low << ", " << high << "]" << endl;

        int pi = partition(arr, low, high);

        cout << "После разделения: ";
        print(arr, size, "");
        cout << "----------------------------------------" << endl;

        quickSort(arr, low, pi, size);
        quickSort(arr, pi + 1, high, size);
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int arr[] = { 6,3,7,1,2,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    print(arr, n, "");

    quickSort(arr, 0, n - 1, n);

    cout << "Отсортированный массив: ";
    print(arr, n, "");

    return 0;
}