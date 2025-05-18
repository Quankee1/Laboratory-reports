#include <iostream>
#include <queue>
#include "Pair.h"
using namespace std;

void fill_pq(priority_queue<Pair>& pq) 
{
    int n;
    cout << "���������� ���������: ";
    cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        Pair p;
        cin >> p;
        pq.push(p);
    }
}

void add_average(priority_queue<Pair>& pq) 
{
    if (pq.empty()) return;

    priority_queue<Pair> temp = pq;
    Pair sum;
    size_t count = 0;

    while (!temp.empty()) 
    {
        sum += temp.top();
        temp.pop();
        count++;
    }

    Pair avg(sum.get_first() / count, sum.get_second() / count);
    pq.push(avg);
}

void remove_in_range(priority_queue<Pair>& pq, const Pair& min_val, const Pair& max_val) 
{
    priority_queue<Pair> temp;

    while (!pq.empty()) {
        Pair p = pq.top();
        pq.pop();

        if (p < min_val || max_val < p) 
        {
            temp.push(p);
        }
    }

    pq = temp;
}

void print_pq(priority_queue<Pair> pq)
{
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void add_min_max_sum(priority_queue<Pair>& pq) 
{
    if (pq.empty()) return;

    priority_queue<Pair> temp = pq;
    Pair min_val = temp.top();
    Pair max_val = temp.top();

    while (!temp.empty()) 
    {
        Pair p = temp.top();
        min_val = (p < min_val) ? p : min_val;
        max_val = (max_val < p) ? p : max_val;
        temp.pop();
    }

    Pair sum = min_val + max_val;

    priority_queue<Pair> new_pq;
    temp = pq;

    while (!temp.empty()) 
    {
        Pair p = temp.top();
        new_pq.push(p + sum);  // ��������� ����� � ������� ��������
        temp.pop();
    }

    pq = new_pq;
}

void show_menu() 
{
    cout << "\n=== ���� ������� � ����������� ===" << endl;
    cout << "1. ��������� �������" << endl;
    cout << "2. �������� ������� ��������������" << endl;
    cout << "3. ������� �������� � ���������" << endl;
    cout << "4. �������� (min+max) � ���������" << endl;
    cout << "5. ������� �������" << endl;
    cout << "0. �����" << endl;
    cout << "�������� ��������: ";
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    priority_queue<Pair> pq;
    int choice;

    do {
        show_menu();
        cin >> choice;

        switch (choice) {
        case 1:
            pq = priority_queue<Pair>(); 
            fill_pq(pq);
            break;
        case 2:
            add_average(pq);
            cout << "������� ���������" << endl;
            break;
        case 3: {
            Pair min, max;
            cout << "������� ����������� ��������: ";
            cin >> min;
            cout << "������� ������������ ��������: ";
            cin >> max;
            remove_in_range(pq, min, max);
            cout << "�������� �������" << endl;
            break;
        }
        case 4:
            add_min_max_sum(pq);
            cout << "(min+max) ��������� � ���������" << endl;
            break;
        case 5:
            cout << "������� �������: ";
            print_pq(pq);
            break;
        case 0:
            cout << "�����" << endl;
            break;
        default:
            cout << "�������� �����!" << endl;
        }
    } while (choice != 0);

    return 0;
}