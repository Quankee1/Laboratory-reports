#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
	char data[100];
	Node* next;
};

struct Stack
{
	int size;
	Node* head = nullptr;
};

void init(Stack& s, char* value)
{
	Node* newNode = new Node;
	strcpy(newNode->data, value);
	newNode->next = nullptr;
	s.head = newNode;
	s.size = 1;
}

void push(Stack& s, char* value)
{
	Node* newNode = new Node;
	strcpy(newNode->data, value);

	if (s.head == nullptr) 
	{
		newNode->next = nullptr; 
	}
	else
	{
		newNode->next = s.head;
	}

	s.head = newNode;
	s.size++;
}

void del_el(Stack& s, char* key)
{
	Stack new_s;
	new_s.size = 0;
	new_s.head = nullptr;
	Node* temp = s.head;

	while (temp != nullptr)
	{
		Node* nextNode = temp->next;
		if (strcmp(temp->data, key) != 0)
		{
			push(new_s, temp->data);
		}
		delete temp;
		temp = nextNode;
	}

	Stack reversed_s;
	reversed_s.size = 0;
	reversed_s.head = nullptr;
	temp = new_s.head;
	while (temp != nullptr)
	{
		push(reversed_s, temp->data);
		temp = temp->next;
	}

	s = reversed_s;
}

void insert(Stack& s, int k, int index)
{
	Stack temp_s;
	temp_s.size = 0;
	temp_s.head = nullptr;

	Node* temp = s.head;

	for (int i = 0; i < index; i++)
	{
		push(temp_s, temp->data);
		Node* nextNode = temp->next;		
		delete temp;
		temp = nextNode;
		s.size--;
	}
	s.head = temp;

	for (int i = 0; i < k; i++)
	{
		Node* newNode = new Node;
		cout << "Введите элемент: ";
		cin >> newNode->data;
		newNode->next = s.head;
		s.head = newNode;
		s.size++;
	}

	while (temp_s.head != nullptr)
	{
		push(s, temp_s.head->data);
		Node* nextNode = temp_s.head->next;
		delete temp_s.head;
		temp_s.head = nextNode;
		temp_s.size--;
	}
}

void print(Stack s)
{
	Node* temp = s.head;

	cout << "Верх -> ";
	while (temp != nullptr)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << " -> Низ " << endl;
}

void addfile(Stack& s, FILE* fp)
{
	Node* temp = s.head;
	int i = 0;
	while (temp != nullptr)
	{
		fprintf(fp, "Элемент %d: %s\n", i++, temp->data);
		temp = temp->next;
	}
} 

void readfile(Stack& s, FILE* fp)
{
	char lines[100][100];
	int count = 0;

	int index;
	char data[100];

	while (fscanf(fp, "Элемент %d: %s\n", &index, data) == 2)
	{
		strcpy(lines[count++], data);
	}

	for (int i = count - 1; i >= 0; i--)
	{
		push(s, lines[i]);
	}
}

void del_s(Stack& s)
{
	Node* temp = s.head;
	while (temp != nullptr)
	{
		s.head = s.head->next;
		delete temp;
		temp = s.head;
	}

	s.head = nullptr;
	s.size = 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Stack s;
	int len;
	cout << "Введите количество элементов в стеке: ";
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		char val[100];
		cout << "Введите элемент: ";
		cin >> val;
		if (i == 0) init(s, val);

		else
		{
			push(s, val);
		}
	}
	cout << endl;
	print(s);

	char key[100];
	cout << "Введите ключ элемента, который необходимо удалить: ";
	cin >> key;
	del_el(s, key);
	cout << endl;
	print(s);

	int k, index;
	cout << "Введите кол-во элементов для вставки и перед каким индексом вставить новые элементы: ";
	cin >> k >> index;
	insert(s, k, index);
	print(s);

	FILE* fp = fopen("F1.txt", "w");
	addfile(s, fp);
	fclose(fp);
	del_s(s);
	cout << "Стек после удаления: ";
	print(s);

	FILE* in = fopen("F1.txt", "r");
	readfile(s, in);
	cout << "Стек после восстановления из файла: ";
	print(s);
	fclose(in);

	return 0;
}