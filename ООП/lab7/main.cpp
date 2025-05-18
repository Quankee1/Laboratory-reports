#include <iostream>
#include "List.h"
#include "Pair.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    List<int> intList1(3, 5);    // Список из 3 элементов со значением 5
    List<int> intList2(3, 2);    // Список из 3 элементов со значением 2
    List<float> floatList(4, 1.5f); // Список из 4 элементов со значением 1.5
    List<double> doubleList(2, 3.7); // Список из 2 элементов со значением 3.7

    cout << "=== Тест для int ===" << endl;
    cout << "intList1: " << intList1; 
    cout << "intList2: " << intList2;
    cout << "Размер intList1: " << intList1() << endl; 
    cout << "Доступ по индексу [1]: " << intList1[1] << endl; 
    List<int> intMult = intList1 * intList2;
    cout << "Результат умножения intList1 * intList2: " << intMult << endl;

    cout << "\n=== Тест для float ===" << endl;
    cout << "floatList: " << floatList;
    cout << "Размер floatList: " << floatList() << endl;

    cout << "\n=== Тест для double ===" << endl;
    cout << "doubleList: " << doubleList;
    cout << "Доступ по индексу [0]: " << doubleList[0] << endl;

    List<Pair<int, double>> pairList(1, Pair<int, double>(0, 0.0)); // Создаём пустой список
    pairList.pushback(Pair<int, double>(1, 2.5)); 
    pairList.pushback(Pair<int, double>(3, 4.7));
    pairList.pushfront(Pair<int, double>(5, 6.9));

    cout << "\n=== Тест для Pair ===" << endl;
    cout << "pairList: " << pairList; 
    cout << "Размер pairList: " << pairList() << endl;
    cout << "Доступ по индексу [1]: " << pairList[1] << endl; // Вывод: 0 : 0

    Pair<int, double> p1 = pairList[0];
    Pair<int, double> p2 = pairList[1];
    Pair<int, double> pDiff = p2 - p1; 
    Pair<int, double> pAddInt = p1 + 10; 
    Pair<int, double> pAddDouble = p2 + 5.5; 

    cout << "p1: " << p1 << endl;    
    cout << "p2: " << p2 << endl;    
    cout << "p2 - p1: " << pDiff << endl;
    cout << "p1 + 10: " << pAddInt << endl; 
    cout << "p2 + 5.5: " << pAddDouble << endl; 

    return 0;
}