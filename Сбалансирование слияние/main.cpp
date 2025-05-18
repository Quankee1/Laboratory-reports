#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

// Функция для слияния двух отсортированных массивов
void merge(int* arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;


    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Слияние временных массивов обратно в arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Рекурсивная сортировка слиянием
void mergeSort(int* arr, int left, int right, int size) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        cout << "Разделение: [";
        for (int i = left; i <= mid; i++) 
        {
            cout << arr[i];
            if (i < mid) cout << ", ";
        }
        cout << "] | [";
        for (int i = mid + 1; i <= right; i++)
        {
            cout << arr[i];
            if (i < right) cout << ", ";
        }
        cout << "]" << endl;

        // Рекурсивная сортировка половин
        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);

        // Слияние отсортированных частей
        merge(arr, left, mid, right);

        cout << "Слияние: [";
        for (int i = left; i <= right; i++) 
        {
            cout << arr[i];
            if (i < right) cout << ", ";
        }
        cout << "]" << endl;
    }
}


int* readFromFile(const char* filename, int& size)
{
    FILE* file = fopen(filename, "r");

    size = 0;
    int temp;
    while (fscanf(file, "%d", &temp) == 1)
        size++;

    int* arr = new int[size];
    rewind(file);
    for (int i = 0; i < size; i++)
        fscanf(file, "%d", &arr[i]);

    fclose(file);
    return arr;
}

void writeToFile(const char* filename, int* arr, int size) 
{
    FILE* file = fopen(filename, "w");

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d", arr[i]);
        if (i < size - 1)
            fprintf(file, " ");
    }

    fclose(file);
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int size;
    int* arr = readFromFile("data.txt", size);

    cout << "Исходный массив: [";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;

    mergeSort(arr, 0, size - 1, size);

    cout << "Отсортированный массив: [";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;

    writeToFile("result.txt", arr, size);
    delete[] arr;

    return 0;
}