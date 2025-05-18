#include <iostream>
using namespace std;

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

}

void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1; 
    int n2 = right - mid; 

    int* leftA = new int[n1];
    int* rightA = new int[n2];

    for (int i = 0; i < n1; i++)
        leftA[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightA[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) 
    {
        if (leftA[i] <= rightA[j])
        {
            arr[k] = leftA[i];
            i++;
        }
        else 
        {
            arr[k] = rightA[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftA[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightA[j];
        j++;
        k++;
    }

    delete[] leftA;
    delete[] rightA;
}

void mergeSort(int arr[], int left, int right) 
 {
    if (left < right) 
    {
        cout << "Разделение: ";
        print(arr + left, right - left + 1);

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);

        cout << "Слияние: ";
        print(arr + left, right - left + 1);
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int arr[] = { 12, 11, 13, 5, 6, 7, 1, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    print(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Отсортированный массив: ";
    print(arr, n);

    return 0;
} 