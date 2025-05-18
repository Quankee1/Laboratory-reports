#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;



// Определение структуры "Студент"
struct Student {
    char lastName[30];  
    char firstName[30]; 
    char middleName[30];
    char birthDate[11]; 
    char address[50];   
    int rating;         
};

// Функция для ввода строки с проверкой на  пустоту
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
            cout << "Ошибка! Ввод не может быть пустым. Попробуйте снова: ";
        }
    }
}



// Функция для записи данных в файл
void writeStudent(FILE* file, Student& s)
{
    if (fwrite(&s, sizeof(Student), 1, file) != 1) 
        cout << "Ошибка при записи в файл!" << endl;
}

// Функция для добавления студента в файл
void addNewStudent(FILE* file, Student& s)
{
    fseek(file, 0, SEEK_END); 
    writeStudent(file, s);  
}

// Функция для печати содержимого файла
void printFile(FILE* file) 
{
    fseek(file, 0, SEEK_SET);  
    Student s;

    while (fread(&s, sizeof(Student), 1, file) == 1) 
    {
        cout << "Фамилия: " << s.lastName << endl;
        cout << "Имя: " << s.firstName << endl;
        cout << "Отчество: " << s.middleName << endl;
        cout << "Дата рождения: " << s.birthDate << endl;
        cout << "Адрес: " << s.address << endl;
        cout << "Рейтинг: " << s.rating << endl;
        cout << "-------------------------" << endl;
    }
}

// Функция для удаления студентов с одинаковой датой рождения
void deleteStudent(FILE* file, const char* birthDate)
{
    FILE* tempFile = fopen("temp.dat", "wb");

    fseek(file, 0, SEEK_SET);
    Student s;
    bool found = false;

    while (fread(&s, sizeof(Student), 1, file) == 1)
    {
        if (strcmp(s.birthDate, birthDate) != 0)
            fwrite(&s, sizeof(Student), 1, tempFile);  // Записываем студентов, дата которых не совпадает
        else
            found = true;
    }

    fclose(file);
    fclose(tempFile);

    if (found) 
    {
        remove("students.dat");
        rename("temp.dat", "students.dat");
        cout << "Студенты с такой датой рождения удалены." << endl;
    }
    else 
    {
        cout << "Студенты с такой датой рождения не найдены." << endl;
        remove("temp.dat");
    }
}

// Функция для добавления студента перед студентом с заданной фамилией
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
            fwrite(&newStudent, sizeof(Student), 1, tempFile);  // Добавляем нового студента перед найденным
            added = true;
        }
        fwrite(&s, sizeof(Student), 1, tempFile);
    }

    if (added == false)
        cout << "Студента с такой фамилией нет в файле!" << endl;
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

    FILE* file = fopen("students.dat", "r+b");  // Открываем файл для чтения и записи
    if (!file)
        file = fopen("students.dat", "wb");  // Если файл не существует, создаём новый
    int choice;
    do {
        cout << "Меню:\n";
        cout << "1. Добавить нового студента в конец файла\n";
        cout << "2. Печать всех студентов\n";
        cout << "3. Удалить студентов с заданной датой рождения\n";
        cout << "4. Добавить студента перед студентом с заданной фамилией\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();  // Очищаем буфер ввода

        switch (choice)
        {
        case 1: {
            // Ввод данных нового студента
            Student s;
            cout << "Введите фамилию: ";
            inputString(s.lastName, sizeof(s.lastName));
            cout << "Введите имя: ";
            inputString(s.firstName, sizeof(s.firstName));
            cout << "Введите отчество: ";
            inputString(s.middleName, sizeof(s.middleName));
            cout << "Введите дату рождения (dd.mm.yyyy): ";
            inputString(s.birthDate, sizeof(s.birthDate));
            cout << "Введите адрес: ";
            inputString(s.address, sizeof(s.address));
            cout << "Введите рейтинг: ";
            cin >> s.rating;
            cin.ignore();  // Очищаем буфер

            // Добавляем студента
            addNewStudent(file, s);
            break;
        }
        case 2:{
            // Печать всех студентов
            cout << "Все студенты:\n";
            printFile(file);
            break;
        }
        case 3: {
            // Удаление студентов по дате рождения
            char birthDate[11];
            cout << "Введите дату рождения (dd.mm.yyyy) для удаления студентов: ";
            inputString(birthDate, sizeof(birthDate));
            deleteStudent(file, birthDate);
            break;
        }
        case 4: {
            // Ввод данных нового студента
            Student s;
            char lastName[20];
            cout << "Введите фамилию: ";
            inputString(s.lastName, sizeof(s.lastName));
            cout << "Введите имя: ";
            inputString(s.firstName, sizeof(s.firstName));
            cout << "Введите отчество: ";
            inputString(s.middleName, sizeof(s.middleName));
            cout << "Введите дату рождения (dd.mm.yyyy): ";
            inputString(s.birthDate, sizeof(s.birthDate));
            cout << "Введите адрес: ";
            inputString(s.address, sizeof(s.address));
            cout << "Введите рейтинг: ";
            cin >> s.rating;
            cin.ignore();
            cout << "Введите перед какой фамилией вставить нового студента: ";
            inputString(lastName, sizeof(lastName));

            // Добавляем студента
            addStudent(file, s, lastName);
            break;
        }
        case 5:
            cout << "Выход.\n";
            break;
        default:
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    } while (choice != 5);

    fclose(file);
    return 0;
}