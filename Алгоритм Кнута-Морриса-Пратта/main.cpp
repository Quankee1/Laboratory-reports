#include <iostream>
#include <cstring> // для strlen
using namespace std;

void Prefix(const char* pat, int patLen, int prefix[]) 
{
    int len = 0; 
    prefix[0] = 0; 

    // Вычисляем префикс-функцию для всех символов шаблона
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

    int i = 0; // Индекс в тексте
    int j = 0; 

    while (i < textLen) 
    {
        // Если символы совпали, двигаемся дальше
        if (pat[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == patLen) 
        {
            return i - j;
        }

        // Если символы не совпали
        if (i < textLen && pat[j] != text[i]) 
        {
            if (j != 0) 
            {
                // Используем префикс-функцию для сдвига шаблона
                j = prefix[j - 1];
            }
            else 
            {
                // Если j == 0, просто сдвигаем текст
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

    cout << "Исходная строка: " << text << endl;
    cout << "Образ: " << pat << endl;

    int pos = findKMP(text, pat);

    if (pos != -1)
        cout << "Подстрока найдена на индексе: " << pos << endl;
    else
        cout << "Подстрока не найдена." << endl;

    return 0;
}