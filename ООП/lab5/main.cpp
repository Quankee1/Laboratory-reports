#include "Vector.h"
#include "Person.h"
#include "Student.h"
#include <iostream>
using namespace std;

void print(Object& obj) 
{
    obj.Show(); // ����������� �����
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    
    cout << "\n--- �������� �������� ---" << endl;
    Person* person1 = new Person("����", 35);
    Student* student1 = new Student("����", 20, "����������", 4);
    Student* student2 = new Student("����", 22, "������", 2);

    cout << "\n--- ������������� ��������� ---" << endl;
    cout << "Person 1:\n" << *person1 << endl;
    cout << "\nStudent 1:\n" << *student1 << endl;

    Person* person2 = new Person(*person1); // ���������� �����������
    cout << "\nPerson 2 (����� person1):\n" << *person2 << endl;

    cout << "\n--- ������ � �������� ---" << endl;
    Vector vec(4);
    vec.Add(person1);
    vec.Add(student1);
    vec.Add(student2);
    vec.Add(new Student("�����", 21, "�����", 3));

    cout << "���������� �������:\n" << vec << endl;

    cout << "\n--- ������������ ������������ ---" << endl;
    print(*person1);
    print(*student1);

    cout << "\n--- �������� ������ ---" << endl;
    if (student2->bad_mark()) 
    {
        cout << "� " << student2->get_name() << " ������ ������!" << endl;
    }

    cout << "\n--- ������� ����������� ---" << endl;
    Object* obj = new Student("������", 23, "��������", 5);
    cout << "����� ����� ��������� �� ������� �����:\n";
    obj->Show();

    delete person2;

    return 0;
}