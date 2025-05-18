#include "Vector.h"
#include "Person.h"
#include "Student.h"
#include <iostream>
using namespace std;

void print(Object& obj) 
{
    obj.Show(); // Полиморфный вызов
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    
    cout << "\n--- Создание объектов ---" << endl;
    Person* person1 = new Person("Иван", 35);
    Student* student1 = new Student("Анна", 20, "Математика", 4);
    Student* student2 = new Student("Петр", 22, "Физика", 2);

    cout << "\n--- Перегруженные операторы ---" << endl;
    cout << "Person 1:\n" << *person1 << endl;
    cout << "\nStudent 1:\n" << *student1 << endl;

    Person* person2 = new Person(*person1); // Копирующий конструктор
    cout << "\nPerson 2 (копия person1):\n" << *person2 << endl;

    cout << "\n--- Работа с вектором ---" << endl;
    Vector vec(4);
    vec.Add(person1);
    vec.Add(student1);
    vec.Add(student2);
    vec.Add(new Student("Мария", 21, "Химия", 3));

    cout << "Содержимое вектора:\n" << vec << endl;

    cout << "\n--- Демонстрация полиморфизма ---" << endl;
    print(*person1);
    print(*student1);

    cout << "\n--- Проверка оценок ---" << endl;
    if (student2->bad_mark()) 
    {
        cout << "У " << student2->get_name() << " плохая оценка!" << endl;
    }

    cout << "\n--- Принцип подстановки ---" << endl;
    Object* obj = new Student("Сергей", 23, "Биология", 5);
    cout << "Вызов через указатель на базовый класс:\n";
    obj->Show();

    delete person2;

    return 0;
}