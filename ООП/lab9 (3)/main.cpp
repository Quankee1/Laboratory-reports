#include "List.h"
#include "error.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    try 
    {
        // ������������ ������������ � MaxSizeError
        cout << "1. ������� ������ � 35 ���������� (MAX_SIZE=30):" << endl;
        List bigList(35, 1); 
    }
    catch (MaxSizeError& e) 
    {
        e.what();
    }

    try 
    {
        cout << "\n2. ������� ������ � 3 ����������:" << endl;
        List myList(3, 10);
        cout << myList;

        cout << "\n3. �������� �������� ������� � �������� 5:" << endl;
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

        cout << "\n3. ������� ��� �������� � �������� ������� ���:" << endl;
        myList.popback();
        myList.popback();
        myList.popback();
        myList.popback(); // ������ ������� EmptySizeError
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
        cout << *endIt << endl; // ������� IteratorError
    }
    catch (IteratorError& e)
    {
        e.what();
    }
}