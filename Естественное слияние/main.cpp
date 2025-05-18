#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

void printArray(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printSeries(const int* arr, int start, int length)
{
    cout << "[";
    for (int i = 0; i < length; i++)
    {
        cout << arr[start + i];
        if (i != length - 1) cout << " ";
    }
    cout << "]";
}

int* merge(int* arr1, int size1, int* arr2, int size2)
{
    int* result = new int[size1 + size2];
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            result[k++] = arr1[i++];
        }
        else
        {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) result[k++] = arr1[i++];
    while (j < size2) result[k++] = arr2[j++];

    return result;
}

int getNextRun(int* arr, int size, int pos)
{
    if (pos >= size) return 0;
    int length = 1;
    while (pos + length < size && arr[pos + length - 1] <= arr[pos + length])
    {
        length++;
    }
    return length;
}

void naturalMergeSort(int*& arr, int& size)
{
    if (size <= 1) return;

    int* temp_sort_1 = nullptr;
    int temp_size_1 = 0;

    temp_size_1 = getNextRun(arr, size, 0);
    temp_sort_1 = new int[temp_size_1];
    for (int i = 0; i < temp_size_1; i++)
    {
        temp_sort_1[i] = arr[i];
    }

    cout << "Начальная серия: ";
    printSeries(arr, 0, temp_size_1);
    cout << endl;

    int pos = temp_size_1;
    bool flag = true;
    while (pos < size && flag) {
        int run_length = getNextRun(arr, size, pos);
        flag = (run_length > 0); // проверка, есть ли ещё серия

        if (flag)
        {
            int* run = new int[run_length];
            for (int i = 0; i < run_length; i++)
            {
                run[i] = arr[pos + i];
            }

            cout << "Слияние серий: ";
            printSeries(temp_sort_1, 0, temp_size_1);
            cout << " и ";
            printSeries(arr, pos, run_length);
            cout << endl;

            int* merged = merge(temp_sort_1, temp_size_1, run, run_length);

            delete[] temp_sort_1;
            delete[] run;

            temp_sort_1 = merged;
            temp_size_1 += run_length;
            pos += run_length;

            cout << "Результат после слияния: ";
            printArray(temp_sort_1, temp_size_1);
            cout << endl;
        }
    }

    delete[] arr;
    arr = temp_sort_1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* file = fopen("data.txt", "r");

    int count = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1)
    {
        count++;
    }
    rewind(file);

    int* arr = new int[count];
    for (int i = 0; i < count; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    cout << "Исходный массив: ";
    printArray(arr, count);
    cout << endl;

    naturalMergeSort(arr, count);

    cout << "Отсортированный массив: ";
    printArray(arr, count);

    // Запись в файл result.txt
    FILE* outFile = fopen("result.txt", "w");

    for (int i = 0; i < count; i++)
    {
        fprintf(outFile, "%d ", arr[i]);
    }
    fclose(outFile);

    delete[] arr;
    return 0;
}
