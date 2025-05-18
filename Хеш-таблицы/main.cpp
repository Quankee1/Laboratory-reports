#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath> 
#include <cstdlib> // для rand и srand
#include <cstdio>
#include <ctime> // для time
using namespace std;

// Константы
const int SIZE = 100; // Размер хеш-таблицы
const double A = 0.6180339887; // Константа для хеш-функции

struct Student 
{
    string fio;
    string phone;
    string passport;
    string birthDate;
    bool isDeleted; // Флаг для удалённых элементов
};

int hashFunction(const string& key) 
{
    // Извлекаем день, месяц и год из строки
    int dot1 = key.find('.');
    int dot2 = key.find('.', dot1 + 1); 

    // Преобразуем подстроки в числа
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

    // Если нашли удалённый элемент, перезаписываем его
    if (table[index] != nullptr && table[index]->isDeleted) 
    {
        delete table[index];
    }

    table[index] = new Student(student);
    table[index]->isDeleted = false; // Сбрасываем флаг удаления
}

// Поиск элемента по ключу (дата рождения)
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

    return nullptr; // Элемент не найден
}

void remove(Student* table[], const string& birthDate) 
{
    int index = hashFunction(birthDate);

    while (table[index] != nullptr) 
    {
        if (!table[index]->isDeleted && table[index]->birthDate == birthDate) 
        {
            table[index]->isDeleted = true; // Помечаем как удалённый
            return;
        }
        index = (index + 1) % SIZE;
    }
}

void saveToFile(Student* table[]) 
{
    FILE* file = fopen("Students.txt", "w"); // Открываем файл для записи

    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] != nullptr && !table[i]->isDeleted) 
        {
            fprintf(file, "%s %s %s %s\n", table[i]->fio.c_str(), table[i]->phone.c_str(), table[i]->passport.c_str(), table[i]->birthDate.c_str());
        }
    }

    fclose(file); // Закрываем файл
    cout << "Данные сохранены в файл." << endl;
}

void loadFromFile(Student* table[], int& collisions) {
    FILE* file = fopen("Students.txt", "r"); // Открываем файл для чтения
    // Очищаем текущую таблицу
    for (int i = 0; i < SIZE; i++) 
    {
        if (table[i] != nullptr)
        {
            delete table[i];
            table[i] = nullptr;
        }
    }

    // Чтение данных из файла
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

    fclose(file); // Закрываем файл
    cout << "Данные загружены из файла." << endl;
}



// Генерация случайной даты рождения
string generateBirthDate() {
    int day = rand() % 28 + 1;
    int month = rand() % 12 + 1;
    int year = rand() % 20 + 1980; // Годы от 1980 до 2000
    return to_string(day) + "." + to_string(month) + "." + to_string(year);
}

Student generateStudent() 
{
    Student student;
    student.fio = "Student" + to_string(rand() % 1000);
    student.phone = "+7" + to_string(rand() % 1000000000);
    student.passport = to_string(rand() % 1000000000);
    student.birthDate = generateBirthDate();
    student.isDeleted = false; // Изначально не удалён
    return student;
}


int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(0)); 

    // Создаём хеш-таблицу
    Student* table[SIZE] = { nullptr }; // Инициализируем все элементы как nullptr
    int collisions = 0;

    // Генерация и вставка 40 студентов
    for (int i = 0; i < 40; i++) 
    {
        insert(table, generateStudent(), collisions);
    }
    cout << "Коллизии для 40 объектов: " << collisions << endl;

    saveToFile(table);
    collisions = 0;
    loadFromFile(table, collisions);
    cout << "Коллизии после загрузки из файла: " << collisions << endl;


    // Генерация и вставка 75 студентов
    for (int i = 40; i < 75; i++) 
    {
        insert(table, generateStudent(), collisions);
    }
    cout << "Коллизии для 75 объектов: " << collisions << endl;

    // Генерация и вставка 90 студентов
    for (int i = 75; i < 90; i++) 
    {
        insert(table, generateStudent(), collisions);
    }
    cout << "Коллизии для 90 объектов: " << collisions << endl;

    Student example = { "Молочко Артём Анатольевич", "111", "111", "23.01.2006", false };
    insert(table, example, collisions);

    // Поиск по ключу
    string searchKey = "23.01.2006";
    Student* foundStudent = search(table, searchKey);
    if (foundStudent != nullptr) 
    {
        cout << "Найден студент: " << foundStudent->fio << endl;
    }
    else {
        cout << "Студент с датой рождения " << searchKey << " не найден." << endl;
    }

    // Удаление по ключу
    string deleteKey = "23.01.2006";
    remove(table, deleteKey);
    cout << "Студент с датой рождения " << deleteKey << " удалён." << endl;

    // Освобождение памяти
    for (int i = 0; i < SIZE; i++) 
    {
        if (table[i] != nullptr) 
        {
            delete table[i];
        }
    }

    return 0;
}