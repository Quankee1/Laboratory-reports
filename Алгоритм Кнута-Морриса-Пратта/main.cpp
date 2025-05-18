#include <iostream>
#include <cstring> // ��� strlen
using namespace std;

void Prefix(const char* pat, int patLen, int prefix[]) 
{
    int len = 0; 
    prefix[0] = 0; 

    // ��������� �������-������� ��� ���� �������� �������
    for (int i = 1; i < patLen; i++) 
    {
        
        while (len > 0 && pat[i] != pat[len]) 
        {
            len = prefix[len - 1];
        }

        if (pat[i] == pat[len]) 
        {
            len++;
        }

        prefix[i] = len;
    }
}

int findKMP(const char* text, const char* pat)
{
    int textLen = strlen(text);
    const int patLen = 4;

    int prefix[patLen];
    Prefix(pat, patLen, prefix);

    int i = 0; // ������ � ������
    int j = 0; 

    while (i < textLen) 
    {
        // ���� ������� �������, ��������� ������
        if (pat[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == patLen) 
        {
            return i - j;
        }

        // ���� ������� �� �������
        if (i < textLen && pat[j] != text[i]) 
        {
            if (j != 0) 
            {
                // ���������� �������-������� ��� ������ �������
                j = prefix[j - 1];
            }
            else 
            {
                // ���� j == 0, ������ �������� �����
                i++;
            }
        }
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

    int pos = findKMP(text, pat);

    if (pos != -1)
        cout << "��������� ������� �� �������: " << pos << endl;
    else
        cout << "��������� �� �������." << endl;

    return 0;
}