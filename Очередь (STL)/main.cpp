#include <iostream>
#include <queue>
using namespace std;

// Функция создания очереди
void create_queue(queue<char>& q, int n) 
{
    char value;
    for (int i = 1; i <= n; i++) 
    {
        cout << "Введите элемент #" << i << ": ";
        cin >> value;
        q.push(value);
    }
}

// Функция вывода очереди
void print_q(queue<char> q) 
{
    cout << "Начало -> ";
    while (!q.empty()) 
    {
        cout << q.front() << " -> ";
        q.pop();
    }
    cout << "Конец" << endl;
}

// Функция удаления элемента с заданным ключом
void remove(queue<char>& q, char key)
{
    int size = q.size();
    for (int i = 0; i < size; i++) {
        char front = q.front();
        q.pop();
        if (front != key) {
            q.push(front);
        }
    }
}

// Функция вставки элементов перед n-м элементом
void insert(queue<char>& q, int k, int n) 
{
    queue<char> temp;
    for (int i = 1; i < n; i++) 
    {
        temp.push(q.front());
        q.pop();
    }

    char value;
    for (int i = 0; i < k; i++) 
    {
        cout << "Введите элемент для вставки: ";
        cin >> value;
        temp.push(value);
    }

    while (!q.empty()) 
    {
        temp.push(q.front());
        q.pop();
    }

    swap(q, temp);
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    queue<char> q;
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

    cout << "Очищение динамической памяти... " << endl;
    while (!q.empty())
    {
        q.pop();
    }
    cout << "Завершено." << endl;
    print_q(q);
}
