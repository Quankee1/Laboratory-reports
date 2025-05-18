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
    // ������� ������ ������
    int buckets[10][10];
    int size[10] = { 0 };

    // ������������ ����� �� ������
    for (int i = 0; i < n; i++)
    {
        int t = a[i];
        int c = 0;
        while (t > 0)
        {
            t /= 10;
            c++;
        }
        int idx = c - 1; // ������ ����� (�� ���������� ���� � �����)

        buckets[idx][size[idx]++] = a[i];
    }

    // ����� ����������� ������ ����� �������������
    cout << "����� ����� �������������:" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (size[i] > 0)
        {
            cout << "���� " << i + 1 << " (����� � " << i + 1 << " ������): ";
            for (int j = 0; j < size[i]; j++)
            {
                cout << buckets[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    // ���������� ������� ����� � ����� ��������������� ������
    cout << "����� ����� ����������:" << endl;
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        if (size[i] > 0)
        {
            insertionSort(buckets[i], size[i]);
            cout << "���� " << i + 1 << " (���������������): ";
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

    cout << "�������� ������: ";
    print(a, n);

    bucketSort(a, n);

    cout << "��������������� ������: ";
    print(a, n);

    return 0;
}