#include <iostream>
using namespace std;

const int n = 8;
char board[n][n];
int step = 0; // Счетчик ферзей

// Вывод текущего состояния доски
void print(int step)
{
    cout << "Поставленно ферзей: " << step << endl;
    cout << "  A B C D E F G H" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << 8 - i << " ";
        for (int j = 0; j < n; j++) 
        {
            cout << board[i][j] << " ";
        }
        cout << 8 - i << endl;
    }
    cout << "  A B C D E F G H" << endl;
    cout << "------------------" << endl;
}

// Проверка, можно ли поставить ферзя в указанную клетку
bool flag(int row, int col)
{
    for (int i = 0; i < col; i++) 
    {
        if (board[row][i] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
    {
        if (board[i][j] == 'Q')
            return false;
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) 
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

// Рекурсивная функция для расстановки ферзей
bool place(int col)
{
    if (col >= n)
        return true;

    for (int row = 0; row < n; row++)
    {
        if (flag(row, col))
        {
            board[row][col] = 'Q';
            step++;
            print(step);

            if (place(col + 1))
                return true;

            board[row][col] = '*'; // Если не подходит, то на шаг назад
            step--;
        }
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '*';
        }
    }
    place(0);
    return 0;
}
