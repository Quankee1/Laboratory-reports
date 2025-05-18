#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

void Gets(char s[])
{
    char ch;
    int i = 0;
    bool dot = false; 

    
    while (i < 255 && dot == false)
    {
        ch = cin.get();
        if (ch == '.') 
        {
            s[i] = '.';
            dot = true;
            i++;
        }
        else
        {
            s[i] = ch; 
            i++;
        }
    }
    s[i] = '\0';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > NULL");

    char s[256];
    cout << "Введите строку (не более 255 символов, заканчивающуюся точкой):" << endl;
    Gets(s);
    int len = strlen(s);
    const int height = 20;
    char res[height][256];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < len; j++)
            res[i][j] = ' ';
        res[i][len] = '\0';
    }
    
    for (int x = 0; x < len; x++)
    {
        int y = (sin(x * 0.3) * 10) + 10; // Делаем синус колеблющимся в пределах 0..20
        res[y][x] = s[x]; 
    }

    for (int i = 0; i < height; i++)
        cout << res[i] << endl;

    return 0;
}