#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        cout << "��� gap = " << gap << ":" << endl;
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;

            cout << "����� ������� �������� " << temp << ": ";
            print(arr, n);
        }
        cout << "����� ���������� ���� gap = " << gap << ": ";
        print(arr, n);
        cout << "-----------------------------" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr[] = { 12, 34, 54, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "�������� ������: ";
    print(arr, n);

    shellSort(arr, n);

    cout << "��������������� ������: ";
    print(arr, n);

    return 0;
}