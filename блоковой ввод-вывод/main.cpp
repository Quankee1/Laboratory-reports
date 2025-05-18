#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;



// ����������� ��������� "�������"
struct Student {
    char lastName[30];  
    char firstName[30]; 
    char middleName[30];
    char birthDate[11]; 
    char address[50];   
    int rating;         
};

// ������� ��� ����� ������ � ��������� ��  �������
void inputString(char* str, int m)
{
    bool flag = false; 

    while (!flag)
    {
        cin.getline(str, m);

        if (str[0] != '\0')
        {
            flag = true; 
        }
        else
        {
            cout << "������! ���� �� ����� ���� ������. ���������� �����: ";
        }
    }
}



// ������� ��� ������ ������ � ����
void writeStudent(FILE* file, Student& s)
{
    if (fwrite(&s, sizeof(Student), 1, file) != 1) 
        cout << "������ ��� ������ � ����!" << endl;
}

// ������� ��� ���������� �������� � ����
void addNewStudent(FILE* file, Student& s)
{
    fseek(file, 0, SEEK_END); 
    writeStudent(file, s);  
}

// ������� ��� ������ ����������� �����
void printFile(FILE* file) 
{
    fseek(file, 0, SEEK_SET);  
    Student s;

    while (fread(&s, sizeof(Student), 1, file) == 1) 
    {
        cout << "�������: " << s.lastName << endl;
        cout << "���: " << s.firstName << endl;
        cout << "��������: " << s.middleName << endl;
        cout << "���� ��������: " << s.birthDate << endl;
        cout << "�����: " << s.address << endl;
        cout << "�������: " << s.rating << endl;
        cout << "-------------------------" << endl;
    }
}

// ������� ��� �������� ��������� � ���������� ����� ��������
void deleteStudent(FILE* file, const char* birthDate)
{
    FILE* tempFile = fopen("temp.dat", "wb");

    fseek(file, 0, SEEK_SET);
    Student s;
    bool found = false;

    while (fread(&s, sizeof(Student), 1, file) == 1)
    {
        if (strcmp(s.birthDate, birthDate) != 0)
            fwrite(&s, sizeof(Student), 1, tempFile);  // ���������� ���������, ���� ������� �� ���������
        else
            found = true;
    }

    fclose(file);
    fclose(tempFile);

    if (found) 
    {
        remove("students.dat");
        rename("temp.dat", "students.dat");
        cout << "�������� � ����� ����� �������� �������." << endl;
    }
    else 
    {
        cout << "�������� � ����� ����� �������� �� �������." << endl;
        remove("temp.dat");
    }
}

// ������� ��� ���������� �������� ����� ��������� � �������� ��������
void addStudent(FILE* file, Student newStudent, const char* lastName)
{
    FILE* tempFile = fopen("temp.dat", "wb");
    fseek(file, 0, SEEK_SET);
    Student s;
    bool added = false;

    while (fread(&s, sizeof(Student), 1, file) == 1)
    {
        if (added == false && strcmp(s.lastName, lastName) == 0) 
        {
            fwrite(&newStudent, sizeof(Student), 1, tempFile);  // ��������� ������ �������� ����� ���������
            added = true;
        }
        fwrite(&s, sizeof(Student), 1, tempFile);
    }

    if (added == false)
        cout << "�������� � ����� �������� ��� � �����!" << endl;
    else
            

    fclose(file);
    fclose(tempFile);

    remove("students.dat");
    rename("temp.dat", "students.dat");
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > NULL");

    FILE* file = fopen("students.dat", "r+b");  // ��������� ���� ��� ������ � ������
    if (!file)
        file = fopen("students.dat", "wb");  // ���� ���� �� ����������, ������ �����
    int choice;
    do {
        cout << "����:\n";
        cout << "1. �������� ������ �������� � ����� �����\n";
        cout << "2. ������ ���� ���������\n";
        cout << "3. ������� ��������� � �������� ����� ��������\n";
        cout << "4. �������� �������� ����� ��������� � �������� ��������\n";
        cout << "5. �����\n";
        cout << "�������� ��������: ";
        cin >> choice;
        cin.ignore();  // ������� ����� �����

        switch (choice)
        {
        case 1: {
            // ���� ������ ������ ��������
            Student s;
            cout << "������� �������: ";
            inputString(s.lastName, sizeof(s.lastName));
            cout << "������� ���: ";
            inputString(s.firstName, sizeof(s.firstName));
            cout << "������� ��������: ";
            inputString(s.middleName, sizeof(s.middleName));
            cout << "������� ���� �������� (dd.mm.yyyy): ";
            inputString(s.birthDate, sizeof(s.birthDate));
            cout << "������� �����: ";
            inputString(s.address, sizeof(s.address));
            cout << "������� �������: ";
            cin >> s.rating;
            cin.ignore();  // ������� �����

            // ��������� ��������
            addNewStudent(file, s);
            break;
        }
        case 2:{
            // ������ ���� ���������
            cout << "��� ��������:\n";
            printFile(file);
            break;
        }
        case 3: {
            // �������� ��������� �� ���� ��������
            char birthDate[11];
            cout << "������� ���� �������� (dd.mm.yyyy) ��� �������� ���������: ";
            inputString(birthDate, sizeof(birthDate));
            deleteStudent(file, birthDate);
            break;
        }
        case 4: {
            // ���� ������ ������ ��������
            Student s;
            char lastName[20];
            cout << "������� �������: ";
            inputString(s.lastName, sizeof(s.lastName));
            cout << "������� ���: ";
            inputString(s.firstName, sizeof(s.firstName));
            cout << "������� ��������: ";
            inputString(s.middleName, sizeof(s.middleName));
            cout << "������� ���� �������� (dd.mm.yyyy): ";
            inputString(s.birthDate, sizeof(s.birthDate));
            cout << "������� �����: ";
            inputString(s.address, sizeof(s.address));
            cout << "������� �������: ";
            cin >> s.rating;
            cin.ignore();
            cout << "������� ����� ����� �������� �������� ������ ��������: ";
            inputString(lastName, sizeof(lastName));

            // ��������� ��������
            addStudent(file, s, lastName);
            break;
        }
        case 5:
            cout << "�����.\n";
            break;
        default:
            cout << "�������� �����, ���������� �����.\n";
        }
    } while (choice != 5);

    fclose(file);
    return 0;
}