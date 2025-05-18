#include <list>
#include "Pair.h"
#include <iostream>
using namespace std;

void fill_pairs(list<Pair>& lst)
{
    int n;
    cout << "Количество элементов: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        Pair p;
        cin >> p;
        lst.push_back(p);
    }
}

void add_pair_average(list<Pair>& lst)
{
    if (lst.empty()) return;

    Pair sum;
    for (const Pair& p : lst)
    {
        sum += p.get_first();
        sum += p.get_second();
    }

    Pair avg(sum.get_first() / lst.size(), sum.get_second() / lst.size());
    lst.push_back(avg);
}


void remove_in_range(list<Pair>& lst, int min_val, int max_val)
{
    lst.remove_if([min_val, max_val](const Pair& p)
        {
            return p.get_first() >= min_val && p.get_first() <= max_val;
        });
}

void add_min_max_sum(list<Pair>& lst)
{
    if (lst.empty()) return;

    int min_f = lst.front().get_first();
    int max_f = min_f;
    double min_s = lst.front().get_second();
    double max_s = min_s;

    for (const Pair& p : lst)
    {
        if (p.get_first() < min_f) min_f = p.get_first();
        if (p.get_first() > max_f) max_f = p.get_first();
        if (p.get_second() < min_s) min_s = p.get_second();
        if (p.get_second() > max_s) max_s = p.get_second();
    }

    Pair sum(min_f + max_f, min_s + max_s);
    for (Pair& p : lst) {
        p += sum.get_first();
        p += sum.get_second();
    }
}

void print_pairs(const list<Pair>& lst)
{
    for (const Pair& p : lst) {
        cout << p << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    list<Pair> pairs;
    int choice;

    do {
        cout << "\n1. Заполнить список\n"
            << "2. Добавить среднее\n"
            << "3. Удалить по диапазону first\n"
            << "4. Добавить (min+max) к элементам\n"
            << "5. Вывести список\n"
            << "0. Выход\n"
            << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            pairs.clear();
            fill_pairs(pairs);
            break;
        case 2:
            add_pair_average(pairs);
            break;
        case 3: {
            int min, max;
            cout << "Границы диапазона: ";
            cin >> min >> max;
            remove_in_range(pairs, min, max);
            break;
        }
        case 4:
            add_min_max_sum(pairs);
            break;
        case 5:
            print_pairs(pairs);
            break;
        }
    } while (choice != 0);

    return 0;
}