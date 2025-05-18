#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
	char data; 
	Node* next;
};

struct Queue 
{ 
	int size;
	Node* head; // Указывает на первый элемент (голову)
	Node* tail; // Указывает на последний элемент (хвост)
};

// Инициализация очереди
void initQueue(Queue& q, char value)
{
	Node* newNode = new Node;
	newNode->data = value;
	q.head = newNode;
	q.tail = newNode;
	q.size = 1;
}

void push(Queue& q, char data)
{
	Node* newNode = new Node{ data, nullptr };
	q.size++;
	if (q.tail == nullptr)
	{
		q.head = newNode;
		q.tail = newNode;
	}
	else 
	{
		q.tail->next = newNode;
		q.tail = newNode;
	}
}

void pop(Queue& q)
{
	Node* temp = q.head;
	q.head = q.head->next;
	q.size--;
	delete temp;
}

void remove(Queue& q, char key)
{
	int size = q.size;
	for (int i = 1; i <= size; i++) // Пробегаемся по всей очереди
	{
		if (q.head->data == key)
			pop(q);

		else
		{
			// Если ключ не найден, перемещаем первый элемент в конец очереди
			push(q, q.head->data);
			pop(q);
		}
	}
}


void create_queue(Queue& q, int n)
{
	char value;
	cout << "Введите элемент #1: ";
	cin >> value;
	initQueue(q, value);
	for (int i = 2; i <= n; i++)
	{
		cout << "Введите элемент #" << i << ": ";
		cin >> value;
		push(q, value);
	}
}

void insert(Queue& q, int k, int n)
{
	for (int i = 1; i < n; i++)
	{
		push(q, q.head->data);
		pop(q);
	}

	char value;
	for (int i = 1; i <= k; i++)
	{
		cout << "Введите элемент для вставки: ";
		cin >> value;
		push(q, value);
	}
	
	int size = q.size;
	for (int i = n; i <= size - k; i++)
	{
		push(q, q.head->data);
		pop(q);
	}
}

void print_q(Queue& q)
{
	cout << "Начало -> ";
	Node* temp = q.head; // Временный указатель
	while (temp != nullptr)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "Конец" << endl;
}

void addfile(Queue& q, FILE*& fp)
{
	Node* temp = q.head;
	int i = 0;
	while (temp != nullptr)
	{
		fprintf(fp, "Элемент %d: %c\n", i++, temp->data);
		temp = temp->next;
	}
}

void delete_q(Queue& q)
{
	while (q.head != nullptr)
		pop(q);

	q.head = nullptr;
	q.tail = nullptr;
	q.size = 0;
}

void readfile(Queue& q, FILE*& fp)
{
	int index;
	char data;

	while (fscanf(fp, "Элемент %d: %c\n", &index, &data) == 2)
	{
		push(q, data);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Queue q;
	int n;
	cout << "Введите количество элементов в очереди: ";
	cin >> n;

	create_queue(q, n);
	cout << endl;
	print_q(q);
	cout << endl;

	char key;
	cout << "Введите ключ элемента, который необходимо удалить: ";
	cin >> key;
	remove(q, key);
	cout << endl;
	print_q(q);

	int k, m;
	cout << "Введите номер элемента, перед которым нужно вставить элементы: ";
	cin >> m;
	cout << "Введите кол-во элементов: ";
	cin >> k;
	insert(q, k, m);
	cout << endl;
	print_q(q);

	FILE* fp = fopen("F1.txt", "w");
	addfile(q, fp);
	fclose(fp);

	cout << "Очищение динамической памяти... " << endl;
	delete_q(q);
	cout << "Завершено." << endl;
	print_q(q);

	fp = fopen("F1.txt", "r");
	readfile(q, fp);
	fclose(fp);
	cout << "Очередь восстановлена из файла:" << endl;
	print_q(q);
}