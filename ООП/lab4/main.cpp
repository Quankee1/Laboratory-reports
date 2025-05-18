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

    cout << "=== �������� �������� ===" << endl;
    Person ivan("����", 30);
    Student maria("�����", 20, "������", 2);

    cout << "\n=== ������������� ��������� ===" << endl;
    // �������� ������������
    Person ivan_copy;
    ivan_copy = ivan;
    cout << "����� �����:\n" << ivan_copy << endl;

    Student new_student;
    cout << "\n������� ������ �������� (��� ������� ������� ������):\n";
    cin >> new_student;
    cout << "����� �������:\n" << new_student << endl;

    cout << "\n=== ������� ����������� ===" << endl;
    // �������� Student � �������, ��������� Person
    print(ivan);    // � Person
    print(maria);   // � Student

    Person test = create_person("����", 99);
    cout << "\n��������� ������:\n" << test << endl;

    return 0;
}