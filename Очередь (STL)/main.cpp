#include <iostream>
#include <queue>
using namespace std;

// ������� �������� �������
void create_queue(queue<char>& q, int n) 
{
    char value;
    for (int i = 1; i <= n; i++) 
    {
        cout << "������� ������� #" << i << ": ";
        cin >> value;
        q.push(value);
    }
}

// ������� ������ �������
void print_q(queue<char> q) 
{
    cout << "������ -> ";
    while (!q.empty()) 
    {
        cout << q.front() << " -> ";
        q.pop();
    }
    cout << "�����" << endl;
}

// ������� �������� �������� � �������� ������
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

// ������� ������� ��������� ����� n-� ���������
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
        cout << "������� ������� ��� �������: ";
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
    cout << "������� ���������� ��������� � �������: ";
    cin >> n;

    create_queue(q, n);
    cout << endl;
    print_q(q);
    cout << endl;

    char key;
    cout << "������� ���� ��������, ������� ���������� �������: ";
    cin >> key;
    remove(q, key);
    cout << endl;
    print_q(q);

    int k, m;
    cout << "������� ����� ��������, ����� ������� ����� �������� ��������: ";
    cin >> m;
    cout << "������� ���-�� ���������: ";
    cin >> k;
    insert(q, k, m);
    cout << endl;
    print_q(q);

    cout << "�������� ������������ ������... " << endl;
    while (!q.empty())
    {
        q.pop();
    }
    cout << "���������." << endl;
    print_q(q);
}
