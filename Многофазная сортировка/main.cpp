#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 14;

int fibonacci(int n)
{
    if (n <= 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int split_into_runs(int arr[], int size, int runs[][MAX], int run_lengths[])
{
    int run_count = 0, idx = 0;
    runs[run_count][idx++] = arr[0];

    for (int i = 1; i < size; ++i) 
    {ш
        if (arr[i] >= arr[i - 1]) 
        {
            runs[run_count][idx++] = arr[i];
        }
        else 
        {
            run_lengths[run_count] = idx;
            run_count++;
            idx = 0;
            runs[run_count][idx++] = arr[i];
        }
    }
    run_lengths[run_count] = idx;
    return run_count + 1;
}

void print_array(const char* label, int arr[], int size) 
{
    printf("%s: ", label);
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int A[], int sizeA, int B[], int sizeB, int result[], int& sizeResult) 
{
    printf("Слияние: ");
    print_array("A", A, sizeA);
    print_array("B", B, sizeB);

    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) 
    {
        if (A[i] < B[j])
            result[k++] = A[i++];
        else
            result[k++] = B[j++];
    }
    while (i < sizeA) result[k++] = A[i++];
    while (j < sizeB) result[k++] = B[j++];
    sizeResult = k;

    print_array("Результат", result, sizeResult);
    printf("------\n");
}

void copy_array(int src[], int len, int dst[])
{
    for (int i = 0; i < len; ++i)
        dst[i] = src[i];
}

void merge_groups(int group_idx, int group_indices[][10], int group_sizes[], int runs[][MAX], int run_lengths[], int temp[], int& temp_len)
{
    if (group_idx < 0)
        return;

    for (int i = 0; i < group_sizes[group_idx]; ++i)
    {
        int idx = group_indices[group_idx][i];
        int merged[MAX], merged_len;
        merge(temp, temp_len, runs[idx], run_lengths[idx], merged, merged_len);
        copy_array(merged, merged_len, temp);
        temp_len = merged_len;
    }

    if (group_idx == group_sizes[0])
        cout << "Начинаем слияние последней группы (Группа " << group_idx + 1 << ")" << endl;
    else if (group_idx == 0)
        cout << "Слияние с оставшейся группой (Группа 1)" << endl;
    else
        cout << "Слияние с предпоследней группой (Группа " << group_idx + 1 << ")" << endl;

    merge_groups(group_idx - 1, group_indices, group_sizes, runs, run_lengths, temp, temp_len);
}


void multi_phase_sort(int arr[], int n) 
{
    int runs[10][MAX], run_lengths[10];
    int run_count = split_into_runs(arr, n, runs, run_lengths);

    printf("Найдено серий: %d\n", run_count);
    for (int i = 0; i < run_count; ++i) 
    {
        char label[20];
        sprintf(label, "Серия %d", i + 1);
        print_array(label, runs[i], run_lengths[i]);
    }
    printf("========================\n");

    // Группы по числам Фибоначчи
    int group_indices[10][10];
    int group_sizes[10];
    int group_count = 0, total = 0, fib_idx = 1;

    while (total < run_count) 
    {
        int f = fibonacci(fib_idx++);
        if (total + f > run_count) f = run_count - total;
        group_sizes[group_count] = f;
        for (int i = 0; i < f; ++i)
            group_indices[group_count][i] = total + i;
        total += f;
        group_count++;
    }

    printf("Группы по числам Фибоначчи:\n");
    for (int g = 0; g < group_count; ++g) 
    {
        printf("Группа %d: ", g + 1);
        for (int i = 0; i < group_sizes[g]; ++i) {
            printf("Серия %d ", group_indices[g][i] + 1);
        }
        printf("\n");
    }
    printf("========================\n");

    int temp1[MAX], temp1_len = 0;
    int merged[MAX], merged_len;

    
    printf("Начинаем слияние последней группы (Группа %d)\n", group_count);
    merge_groups(group_count - 1, group_indices, group_sizes, runs, run_lengths, temp1, temp1_len);

    // Запись в файл
    FILE* out = fopen("result.txt", "w");
    for (int i = 0; i < temp1_len; ++i)
        fprintf(out, "%d ", temp1[i]);
    fclose(out);

    printf("Финальный результат:\n");
    print_array("Отсортировано", temp1, temp1_len);
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    FILE* in = fopen("data.txt", "r");
    int arr[MAX], n = 0;

    while (fscanf(in, "%d", &arr[n]) == 1)
        n++;
    fclose(in);

    multi_phase_sort(arr, n);

    return 0;
}
