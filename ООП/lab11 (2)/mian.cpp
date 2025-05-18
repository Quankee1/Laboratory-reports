#include "Pair.h"
#include <list>
#include <iostream>
using namespace std;

template <typename T>
class List 
{
    list<T> data;

public:
    List() = default;

    List(size_t count, const T& value) 
    {
        for (size_t i = 0; i < count; ++i) 
        {
            data.push_back(value);
        }
    }

    List(const List& other) : data(other.data) {}

    void add(const T& item) 
    {
        data.push_back(item);
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
            data.push_back(item);
        }
    }

    void add_min_max_sum() 
    {
        if (data.empty()) return;

        auto min_it = data.begin();
        auto max_it = data.begin();

        for (auto it = data.begin(); it != data.end(); ++it) 
        {
            if (*it < *min_it) min_it = it;
            if (*it > *max_it) max_it = it;
        }

        T sum = *min_it + *max_it;
        for (auto& item : data) 
        {
            item += sum;
        }
    }

    void add_average() 
    {
        if (data.empty()) return;

        T sum = T();
        int count = 0;

        for (const auto& item : data) 
        {
            sum += item;
            count++;
        }

        T average = sum / count;
        data.push_back(average);
    }

    
    void remove_in_range(const T& min_val, const T& max_val) 
    {
        auto it = data.begin();
        while (it != data.end()) {
            if (*it >= min_val && *it <= max_val) 
            {
                it = data.erase(it);
            }
            else 
            {
                ++it;
            }
        }
    }

    void print() const 
    {
        for (const auto& item : data) {
            cout << item << " ";
        }
        cout << endl;
    }
};

void showMenu() 
{
    cout << "\n=== ���� ������ �� ������� ===\n";
    cout << "1. ��������� ������\n";
    cout << "2. �������� �������\n";
    cout << "3. �������� ������� ��������������\n";
    cout << "4. ������� �������� � ���������\n";
    cout << "5. �������� (min+max) � ���������\n";
    cout << "6. �������� ������\n";
    cout << "0. �����\n";
    cout << "�������� ��������: ";
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    List<Pair> myList;
    int choice;
    Pair temp, minVal, maxVal;

    do 
    {
        showMenu();
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            int count;
            cout << "������� ���������� ���������: ";
            cin >> count;
            cout << "������� " << count << " ��� (int double):\n";
            myList.fill();
            break;
        }
        case 2:
            cout << "������� ������� (int double): ";
            cin >> temp;
            myList.add(temp);
            break;
        case 3:
            myList.add_average();
            cout << "������� ��������� � ����� ������\n";
            break;
        case 4:
            cout << "������� ������� ��������� (min max): ";
            cin >> minVal >> maxVal;
            myList.remove_in_range(minVal, maxVal);
            cout << "�������� �������\n";
            break;
        case 5:
            myList.add_min_max_sum();
            cout << "����� min+max ��������� � ���������\n";
            break;
        case 6:
            cout << "������� ������:\n";
            myList.print();
            break;
        case 0:
            cout << "���������� ������\n";
            break;
        default:
            cout << "�������� �����!\n";
            while (cin.get() != '\n') continue;
        }
    } while (choice != 0);

    return 0;
}