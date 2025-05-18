#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    char data[100];
    Node* next = nullptr;
};
struct List
{
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
};

void init(List& l, char* value)
{
    Node* newNode = new Node;
    strcpy(newNode->data, value);
    newNode->next = nullptr;
    l.head = newNode;
    l.tail = newNode;
    l.size = 1;
}

void create(List& l, char* value)
{
    Node* newNode = new Node;
    strcpy(newNode->data, value);
    newNode->next = nullptr;
    l.tail->next = newNode;
    l.tail = newNode;
    l.size++;
}

void del_el(List& l, char* key)
{
    Node* temp = l.head;
    Node* prev = nullptr;

    while (temp != nullptr)
    {
        if (strcmp(temp->data, key) == 0)
        {
            if (temp == l.head)
            {
                l.head = l.head->next;
                delete temp;
                temp = l.head;
            }
            else
            {
                prev->next = temp->next;
                if (temp == l.tail)
                {
                    l.tail = prev;
                }
                delete temp;
                temp = prev->next;
            }
            l.size--;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}

void insert(List& l, int k, int index)
{
    Node* temp = l.head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }

    for (int i = 1; i <= k; i++)
    {
        Node* newNode = new Node;
        cout << "Введите элемент: ";
        cin >> newNode->data;

        if (index == 0) 
        {
            newNode->next = l.head;
            l.head = newNode;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode; 
        }
        l.size++;
    }
}

void print(List l) 
{
    Node* temp = l.head;
    while (temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

void del_l(List& l)
{
    while (l.head != nullptr)
    {
        Node* temp = l.head;
        l.head = l.head->next;
        delete temp;
        l.size--;
    }
    l.head = nullptr;
    l.tail = nullptr;
    l.size = 0;
}

void addfile(List& l, FILE* fp)
{
    Node* temp = l.head;
    int i = 0;
    while (temp != nullptr)
    {
        fprintf(fp, "Элемент %d: %s\n", i++, temp->data);
        temp = temp->next;
    }
}

void readfile(FILE* fp, List& l)
{
    int index;
    char data[100];

    while (fscanf(fp, "Элемент %d: %99[^\n]\n", &index, data) == 2)
    {
        Node* newNode = new Node;
        strcpy_s(newNode->data, data);
        newNode->next = nullptr;
        if (l.head == nullptr)
        {
            l.head = newNode;
            l.tail = newNode;
        }
        else
        {
            l.tail->next = newNode;
            l.tail = newNode;
        }
        l.size++;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List l;
    int len;
    cout << "Введите длину списка: ";
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        char value[100];
        cout << "Введите элемент списка: ";
        cin >> value;
        if (i == 0)
        {
            init(l, value);
        }
        else create(l, value);
    }
    print(l);

    char key[100];
    cout << "Введите ключ для удаления: ";
    cin >> key;
    del_el(l, key);
    print(l);

    int k, index;
    cout << "Введите кол-во элементов для вставки и перед каким индексом вставить новые элементы: ";
    cin >> k >> index;
    insert(l, k, index);
    print(l);

    FILE* fp = fopen("F1.txt", "w");
    addfile(l, fp);
    fclose(fp);
    del_l(l);
    cout << "Список после удаления: ";
    print(l);

    FILE* in = fopen("F1.txt", "r");
    readfile(in, l);
    cout << "Список после восстановления из файла: ";
    print(l);
    fclose(in);
    
    return 0;
}