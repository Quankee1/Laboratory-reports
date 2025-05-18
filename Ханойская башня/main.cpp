#include <iostream>
#include <string>
using namespace std;

void print(string towers[])
{
    cout << "��������� ��������:" << endl;
    for (int i = 0; i < 3; i++) 
    {
        cout << i + 1 << ": " << towers[i] << endl;
    }
    cout << "---------------------" << endl;
}

void disk(int start, int point, string towers[], int& step)
{
    // ��������� ����
    int d_i = towers[start].length() - 1;
    char disk = towers[start][d_i];

    // ������� ��� �� �������
    string temp = "";
    for (int i = 0; i < d_i; i++)
    {
        temp += towers[start][i];
    }
    towers[start] = temp;

    // ��������� ���� �� ������ ��������
    towers[point] += disk;

    cout << "��� " << step++ << ": ����������� ���� " << disk << " � " << start + 1 << " �� " << point + 1 << endl;
    print(towers);
}

void han(int n, int start, int temp, int point, int& step, string towers[])
{
    if (n == 1) {
        disk(start, point, towers, step);
        return;
    }
    han(n - 1, start, point, temp, step, towers);
    disk( start, point, towers, step);
    han(n - 1, temp, start, point, step, towers);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    do {
        cout << "������� ���������� ������: ";
        cin >> n;
        if (n < 1)
            cout << "������������ ����� ������." << endl;
    } while (n < 1);

    // ������� �������
    string towers[3] = { "", "", "" };
    for (int i = n; i >= 1; i--)
    {
        char disk = '0' + i;  
        towers[0] += disk; 
    }

    cout << "��������� ���������:" << endl;
    print(towers);

    int step = 1;
    han(n, 0, 1, 2, step, towers);

    return 0;
}
