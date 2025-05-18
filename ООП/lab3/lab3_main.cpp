#include <iostream>
#include "Pair.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


    cout << "=== Конструкторы ===" << endl;
    Pair p1;               // Конструктор по умолчанию
    Pair p2(10, 3.14);     // Конструктор с параметрами
    Pair p3(p2);           // Конструктор копирования

    cout << "p1: " << p1 << endl;  // 0 : 0
    cout << "p2: " << p2 << endl;  // 10 : 3.14
    cout << "p3: " << p3 << endl;  // 10 : 3.14
    cout << endl;


    cout << "=== Методы set_data и get_first ===" << endl;
    p1.set_data(5, 2.71);
    cout << "p1 после set_data: " << p1 << endl;  // 5 : 2.71
    cout << "p1.get_first(): " << p1.get_first() << endl; 
    cout << endl;

  
    cout << "=== Оператор присваивания = ===" << endl;
    Pair p4;
    p4 = p2;
    cout << "p4 = p2: " << p4 << endl;  // 10 : 3.14
    cout << endl;


    cout << "=== Оператор вычитания - ===" << endl;
    Pair p5 = p2 - p1;
    cout << "p2 - p1: " << p5 << endl;  // (10-5) : (3.14-2.71) -> 5 : 0.43
    cout << endl;


    cout << "=== Операторы += (int и double) ===" << endl;
    p1 += 3;       
    cout << "p1 += 3: " << p1 << endl;  // 8 : 2.71
    p1 += 1.5;     
    cout << "p1 += 1.5: " << p1 << endl;  // 8 : 4.21
    cout << endl;

 
    cout << "=== Ввод/вывод (>> и <<) ===" << endl;
    Pair p6;
    cout << "Введите пару (например, 7 8.8): ";
    cin >> p6;
    cout << "Вы ввели: " << p6 << endl;
    cout << endl;

    return 0;
}