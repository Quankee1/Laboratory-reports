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
    int wall = low; // ������ "������"

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

        print(arr, size, "������� ������");
        cout << "������� �������: " << pivot << endl;
        cout << "��������: [" << low << ", " << high << "]" << endl;
        int new_pivot = partition(arr, low, high, pivot);

        cout << "����� ����������: ";
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

    cout << "�������� ������: "; 
    print(arr, n, "");

    quickSort(arr, 0, n - 1, n);

    cout << "��������������� ������: ";
    print(arr, n, "");

    return 0;
}