#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath> 
#include <cstdlib> // ��� rand � srand
#include <cstdio>
#include <ctime> // ��� time
using namespace std;

// ���������
const int SIZE = 100; // ������ ���-�������
const double A = 0.6180339887; // ��������� ��� ���-�������

struct Student 
{
    string fio;
    string phone;
    string passport;
    string birthDate;
    bool isDeleted; // ���� ��� �������� ���������
};

int hashFunction(const string& key) 
{
    // ��������� ����, ����� � ��� �� ������
    int dot1 = key.find('.');
    int dot2 = key.find('.', dot1 + 1); 

    // ����������� ��������� � �����
    int day = stoi(key.substr(0, dot1)); 
    int month = stoi(key.substr(dot1 + 1, dot2 - dot1 - 1)); 
    int year = stoi(key.substr(dot2 + 1)); 

    int k = day * 10000 + month * 100 + year;

    double fractional;
    modf(k * A, &fractional); 

    return static_cast<int>(SIZE * fractional) % SIZE;
}

void insert(Student* table[], const Student& student, int& collisions)
{
    int index = hashFunction(student.birthDate);

    while (table[index] != nullptr && !table[index]->isDeleted) 
    {
        collisions++;
        index = (index + 1) % SIZE;
    }

    // ���� ����� �������� �������, �������������� ���
    if (table[index] != nullptr && table[index]->isDeleted) 
    {
        delete table[index];
    }

    table[index] = new Student(student);
    table[index]->isDeleted = false; // ���������� ���� ��������
}

// ����� �������� �� ����� (���� ��������)
Student* search(Student* table[], const string& birthDate) 
{
    int index = hashFunction(birthDate);

    while (table[index] != nullptr)  
    {
        if (!table[index]->isDeleted && table[index]->birthDate == birthDate) 
        {
            return table[index];
        }
        index = (index + 1) % SIZE;
    }

    return nullptr; // ������� �� ������
}

void remove(Student* table[], const string& birthDate) 
{
    int index = hashFunction(birthDate);

    while (table[index] != nullptr) 
    {
        if (!table[index]->isDeleted && table[index]->birthDate == birthDate) 
        {
            table[index]->isDeleted = true; // �������� ��� ��������
            return;
        }
        index = (index + 1) % SIZE;
    }
}

void saveToFile(Student* table[]) 
{
    FILE* file = fopen("Students.txt", "w"); // ��������� ���� ��� ������

    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] != nullptr && !table[i]->isDeleted) 
        {
            fprintf(file, "%s %s %s %s\n", table[i]->fio.c_str(), table[i]->phone.c_str(), table[i]->passport.c_str(), table[i]->birthDate.c_str());
        }
    }

    fclose(file); // ��������� ����
    cout << "������ ��������� � ����." << endl;
}

void loadFromFile(Student* table[], int& collisions) {
    FILE* file = fopen("Students.txt", "r"); // ��������� ���� ��� ������
    // ������� ������� �������
    for (int i = 0; i < SIZE; i++) 
    {
        if (table[i] != nullptr)
        {
            delete table[i];
            table[i] = nullptr;
        }
    }

    // ������ ������ �� �����
    char fio[100], phone[20], passport[20], birthDate[20];
    while (fscanf(file, "%s %s %s %s", fio, phone, passport, birthDate) != EOF) 
    {
        Student student;
        student.fio = fio;
        student.phone = phone;
        student.passport = passport;
        student.birthDate = birthDate;
        student.isDeleted = false;

        insert(table, student, collisions); 
    }

    fclose(file); // ��������� ����
    cout << "������ ��������� �� �����." << endl;
}



// ��������� ��������� ���� ��������
string generateBirthDate() {
    int day = rand() % 28 + 1;
    int month = rand() % 12 + 1;
    int year = rand() % 20 + 1980; // ���� �� 1980 �� 2000
    return to_string(day) + "." + to_string(month) + "." + to_string(year);
}

Student generateStudent() 
{
    Student student;
    student.fio = "Student" + to_string(rand() % 1000);
    student.phone = "+7" + to_string(rand() % 1000000000);
    student.passport = to_string(rand() % 1000000000);
    student.birthDate = generateBirthDate();
    student.isDeleted = false; // ���������� �� �����
    return student;
}


int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(0)); 

    // ������ ���-�������
    Student* table[SIZE] = { nullptr }; // �������������� ��� �������� ��� nullptr
    int collisions = 0;

    // ��������� � ������� 40 ���������
    for (int i = 0; i < 40; i++) 
    {
        insert(table, generateStudent(), collisions);
    }
    cout << "�������� ��� 40 ��������: " << collisions << endl;

    saveToFile(table);
    collisions = 0;
    loadFromFile(table, collisions);
    cout << "�������� ����� �������� �� �����: " << collisions << endl;


    // ��������� � ������� 75 ���������
    for (int i = 40; i < 75; i++) 
    {
        insert(table, generateStudent(), collisions);
    }
    cout << "�������� ��� 75 ��������: " << collisions << endl;

    // ��������� � ������� 90 ���������
    for (int i = 75; i < 90; i++) 
    {
        insert(table, generateStudent(), collisions);
    }
    cout << "�������� ��� 90 ��������: " << collisions << endl;

    Student example = { "������� ���� �����������", "111", "111", "23.01.2006", false };
    insert(table, example, collisions);

    // ����� �� �����
    string searchKey = "23.01.2006";
    Student* foundStudent = search(table, searchKey);
    if (foundStudent != nullptr) 
    {
        cout << "������ �������: " << foundStudent->fio << endl;
    }
    else {
        cout << "������� � ����� �������� " << searchKey << " �� ������." << endl;
    }

    // �������� �� �����
    string deleteKey = "23.01.2006";
    remove(table, deleteKey);
    cout << "������� � ����� �������� " << deleteKey << " �����." << endl;

    // ������������ ������
    for (int i = 0; i < SIZE; i++) 
    {
        if (table[i] != nullptr) 
        {
            delete table[i];
        }
    }

    return 0;
}