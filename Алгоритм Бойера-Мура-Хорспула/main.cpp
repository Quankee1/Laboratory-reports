#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 256; // ������ �������� (ASCII)

void ShiftTable(const char* pat, int patLen, int shift[])
{
    // ���������� ��� ������ ����� ����� �������
    for (int i = 0; i < SIZE; i++)
    {
        shift[i] = patLen;
    }

    // ��� �������� ������� ����� ������
    for (int i = 0; i < patLen - 1; i++) 
    {
        shift[(unsigned char)pat[i]] = patLen - 1 - i;
    }
}

int findPattern(const char* text, const char* pat)
{
    int textLen = strlen(text);
    int patLen = strlen(pat);

    int shift[SIZE];
    ShiftTable(pat, patLen, shift);

    int i = 0;
    while (i <= textLen - patLen) 
    {
        int j = patLen - 1; // ������� � �������

        while (j >= 0 && pat[j] == text[i + j]) 
        {
            j--;
        }

        if (j < 0) 
        {
            return i;
        }

        // �������� ������
        i += shift[(unsigned char)text[i + patLen - 1]];
    }

    return -1; 
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    const char* text = "ABACADABRAC";
    const char* pat = "ABRA";

    cout << "�������� ������: " << text << endl;
    cout << "�����: " << pat << endl;

    int pos = findPattern(text, pat);

    if (pos != -1) 
        cout << "��������� ������� �� �������: " << pos << endl;
    else 
        cout << "��������� �� �������." << endl;
    
    return 0;
}