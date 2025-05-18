#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


struct Node
{
	char data[100];
	Node* prev;
	Node* next;
};

struct List
{
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
};

void init(List& l)
{
	Node* newNode = new Node;
	char a[100];
	cout << "Введите строку для элемента списка: ";
	cin >> a;
	strcpy_s(newNode->data, a);
	newNode->prev = nullptr;
	newNode->next = nullptr;
	l.head = newNode;
	l.tail = newNode;
	l.size++;
}

void addEnd(List& l)
{
	Node* newNode = new Node;
	char a[100];
	cout << "Введите строку для добавления элемента списка в конец: ";
	cin >> a;
	strcpy_s(newNode->data, a);
	newNode->next = nullptr;
	newNode->prev = l.tail;
	l.tail->next = newNode;
	l.tail = newNode;
	l.size++;
}
void addStart(List& l)
{
	Node* newNode = new Node;
	char a[100];
	cout << "Введите строку для добавления элемента списка в начало: ";
	cin >> a;
	strcpy_s(newNode->data, a);
	newNode->next = l.head;
	newNode->prev = nullptr;
	l.head->prev = newNode;
	l.head = newNode;
	l.size++;
}

void del_key(List& l, const char* key)
{
	Node* temp = l.head;

	while (temp != nullptr)
	{
		Node* nextNode = temp->next;

		if (strcmp(temp->data, key) == 0)
		{
			if (temp->prev != nullptr)
				temp->prev->next = temp->next;
			else
				l.head = temp->next;

			if (temp->next != nullptr)
				temp->next->prev = temp->prev;
			else
				l.tail = temp->prev;

			delete temp;
			l.size--;
		}
		temp = nextNode;
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
			if (l.size == 0) 
				l.tail = newNode;
		}
		else
		{
			newNode->next = temp->next;
			temp->next = newNode;
			temp = newNode; 
			if (newNode->next == nullptr) 
				l.tail = newNode;
		}
		l.size++;
	}
}


void print(List& l)
{
	Node* temp = l.head;
	while (temp != nullptr)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

void addfile(List& l, FILE*& fp)
{
	Node* temp = l.head;
	int i = 0;
	while (temp != nullptr)
	{
		fprintf(fp, "Элемент %d: %s\n", i++, temp->data);
		temp = temp->next;
	}
}

void del_l(List& l)
{
	Node* temp = l.head;

	while (temp != nullptr)
	{
		Node* nextNode = temp->next;
		delete temp;
		temp = nextNode;
	}
	l.head = nullptr;
	l.tail = nullptr;
	l.size = 0;
}

void readfile(FILE*& fp, List& l) 
{
	int index;
	char data[100];

	while (fscanf(fp, "Элемент %d: %99[^\n]\n", &index, data) == 2)
	{
		Node* newNode = new Node;
		strcpy_s(newNode->data, data);
		newNode->prev = nullptr;
		newNode->next = nullptr;

		if (l.head == nullptr)
		{
			l.head = newNode;
			l.tail = newNode;
		}
		else
		{
			newNode->prev = l.tail;
			l.tail->next = newNode;
			l.tail = newNode;
		}
		l.size++;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int len;
	cout << "Введите длину списка: ";
	cin >> len;
	List l;
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
		{
			init(l);
		}
		else addEnd(l);
	}
	print(l);
	
	addStart(l);
	print(l);

	addEnd(l);
	print(l);

	char key[100];
	cout << "Введите ключ элемента для удаления: ";
	cin >> key;
	del_key(l, key);
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
}
