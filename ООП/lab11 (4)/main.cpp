#pragma once
#include "Pair.h"
#include <queue>
#include <iostream>
using namespace std;

template <typename T>
class List 
{
    priority_queue<T> container; // ������� ����������

public:

    List() = default;
    List(initializer_list<T> init) 
    {
        for (const auto& item : init) 
        {
            container.push(item);
        }
    }

    void add(const T& item) 
    {
        container.push(item);
    }

    void fill() 
    {
        int n;
        cout << "���������� ���������: ";
        cin >> n;

        for (int i = 0; i < n; ++i) 
        {
            T item;
            cin >> item;
            container.push(item);
        }
    }

    void add_average() 
    {
        if (container.empty()) return;

        priority_queue<T> temp = container;
        T sum = T();
        size_t count = 0;

        while (!temp.empty()) 
        {
            sum += temp.top();
            temp.pop();
            count++;
        }

        container.push(sum / count);
    }

    void remove_in_range(const T& min_val, const T& max_val)
    {
        priority_queue<T> temp;

        while (!container.empty()) {
            T item = container.top();
            container.pop();

            if (item < min_val || max_val < item) 
            {
                temp.push(item);
            }
        }

        container = temp;
    }

    void add_min_max_sum() 
    {
        if (container.empty()) return;

        priority_queue<T> temp = container;
        T min_val = temp.top();
        T max_val = temp.top();

        while (!temp.empty()) 
        {
            T item = temp.top();
            if (item < min_val) min_val = item;
            if (max_val < item) max_val = item;
            temp.pop();
        }

        T sum = min_val + max_val;
        temp = container;
        priority_queue<T> new_container;

        while (!temp.empty()) {
            new_container.push(temp.top() + sum);
            temp.pop();
        }

        container = new_container;
    }

    void print() const 
    {
        priority_queue<T> temp = container;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

void show_menu() 
{
    cout << "\n=== ���� ������ � List ===" << endl;
    cout << "1. ��������� ������" << endl;
    cout << "2. �������� �������" << endl;
    cout << "3. �������� ������� ��������������" << endl;
    cout << "4. ������� �������� � ���������" << endl;
    cout << "5. �������� (min+max) � ���������" << endl;
    cout << "6. ������� ������" << endl;
    cout << "0. �����" << endl;
    cout << "�������� ��������: ";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List<Pair> my_list;
    int choice;

    do {
        show_menu();
        cin >> choice;

        switch (choice) 
        {
        case 1:
            my_list.fill();
            break;
        case 2: 
            {
            Pair p;
            cin >> p;
            my_list.add(p);
            break;
        }
        case 3:
            my_list.add_average();
            cout << "������� ���������" << endl;
            break;
        case 4: 
            {
            Pair min, max;
            cout << "������� ����������� ��������: ";
            cin >> min;
            cout << "������� ������������ ��������: ";
            cin >> max;
            my_list.remove_in_range(min, max);
            cout << "�������� �������" << endl;
            break;
        }
        case 5:
            my_list.add_min_max_sum();
            cout << "(min+max) ���������" << endl;
            break;
        case 6:
            cout << "������� ������: ";
            my_list.print();
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