#include "Person.h"
#include "Student.h"
#include <iostream>
using namespace std;

void print(const Person& p) 
{
	cout << p << endl;
}

Person create_person(string name, int age) 
{
	return Person(name, age);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "=== Создание объектов ===" << endl;
    Person ivan("Иван", 30);
    Student maria("Мария", 20, "Физика", 2);

    cout << "\n=== Перегруженные операторы ===" << endl;
    // Оператор присваивания
    Person ivan_copy;
    ivan_copy = ivan;
    cout << "Копия Ивана:\n" << ivan_copy << endl;

    Student new_student;
    cout << "\nВведите данные студента (имя возраст предмет оценка):\n";
    cin >> new_student;
    cout << "Новый студент:\n" << new_student << endl;

    cout << "\n=== Принцип подстановки ===" << endl;
    // Передаем Student в функцию, ожидающую Person
    print(ivan);    // с Person
    print(maria);   // с Student

    Person test = create_person("Тест", 99);
    cout << "\nСозданный объект:\n" << test << endl;

    return 0;
}