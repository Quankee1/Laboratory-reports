#include "List.h"
#include "error.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    try 
    {
        // Тестирование конструктора и MaxSizeError
        cout << "1. Создаем список с 35 элементами (MAX_SIZE=30):" << endl;
        List bigList(35, 1); 
    }
    catch (MaxSizeError& e) 
    {
        e.what();
    }

    try 
    {
        cout << "\n2. Создаем список с 3 элементами:" << endl;
        List myList(3, 10);
        cout << myList;

        cout << "\n3. Пытаемся получить элемент с индексом 5:" << endl;
        cout << myList[5] << endl; 
    }
    catch (IndexError1& e) 
    {
        e.what();
    }
    catch (IndexError2& e)
    {
        e.what();
    }

    try 
    {
        List myList(3, 10);

        cout << "\n3. Удаляем все элементы и пытаемся удалить еще:" << endl;
        myList.popback();
        myList.popback();
        myList.popback();
        myList.popback(); // Должно вызвать EmptySizeError
    }
    catch (EmptySizeError& e) 
    {
        e.what();
    }

    cout << endl;

    try {

        List myList(2, 10);
        Iterator it = myList.first();
        it = it + 2;
        Iterator endIt = myList.last();
        cout << *endIt << endl; // Вызовет IteratorError
    }
    catch (IteratorError& e)
    {
        e.what();
    }
}