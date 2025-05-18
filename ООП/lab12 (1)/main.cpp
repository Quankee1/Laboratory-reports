#include <iostream>
#include "Pair.h"
#include <set>
using namespace std;

template<typename T>
class MyList 
{
private:
    multiset<T> data;

public:
    void insert(const T& value)
    {
        data.insert(value);
    }

    void print() const 
    {
        for (const auto& item : data)
        {
            cout << item << " ";
        }
        cout << endl;
    }

  
    typename multiset<T>::iterator begin() { return data.begin(); }
    typename multiset<T>::iterator end() { return data.end(); }
    typename multiset<T>::const_iterator begin() const { return data.begin(); }
    typename multiset<T>::const_iterator end() const { return data.end(); }

    
    int size() const { return data.size(); }

    
    bool empty() const { return data.empty(); }

 
    template<typename U>
    void removeInRange(U a, U b) 
    {
        auto it = data.begin();
        while (it != data.end()) 
        {
            if (it->get_first() >= a && it->get_first() <= b)
            {
                it = data.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    
    T getAverage() const 
    {
        if (data.empty()) return T();

        T sum;
        for (const auto& item : data)
        {
            sum = sum + item;
        }

        double avgFirst = static_cast<double>(sum.get_first()) / data.size();
        double avgSecond = sum.get_second() / data.size();
        return T(static_cast<int>(avgFirst), avgSecond);
    }

    void addAverage() 
    {
        T avg = getAverage();
        data.insert(avg);
        cout << "Added average: " << avg << endl;
    }

 
    void addMinMaxSum() 
    {
        if (data.empty()) return;

        T min_val = *data.begin();
        T max_val = *data.rbegin();
        T sum = min_val + max_val;
        double value_to_add = sum.get_second();

        multiset<T> temp;
        for (const auto& item : data) 
        {
            temp.insert(item + value_to_add);
        }

        data = temp;

        cout << "Added sum of min(" << min_val << ") and max("
            << max_val << "): " << value_to_add << " to each element" << endl;
    }
};

void showMenu() 
{
    cout << "\n=== Меню ===" << endl;
    cout << "1. Добавить элемент" << endl;
    cout << "2. Вывести содержимое" << endl;
    cout << "3. Добавить среднее арифметическое" << endl;
    cout << "4. Удалить элементы в диапазоне (по first)" << endl;
    cout << "5. Добавить сумму min и max к каждому элементу" << endl;
    cout << "6. Очистить контейнер" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите действие: ";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    MyList<Pair> list;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            int first;
            double second;
            cout << "Введите пару (int first, double second): ";
            cin >> first >> second;
            list.insert(Pair(first, second));
            break;
        }
        case 2:
            cout << "Содержимое: ";
            list.print();
            break;

        case 3:
            list.addAverage();
            break;

        case 4: 
            {
            int a, b;
            cout << "Введите диапазон (a b): ";
            cin >> a >> b;
            list.removeInRange(a, b);
            cout << "Элементы с first в диапазоне [" << a << ", " << b << "] удалены." << endl;
            break;
        }

        case 5:
            list.addMinMaxSum();
            break;

        case 6:
            while (!list.empty()) 
            {
                int val = list.begin()->get_first();
                list.removeInRange(val, val);
            }
            cout << "Контейнер очищен." << endl;
            break;

        case 0:
            cout << "Выход." << endl;
            break;

        default:
            cout << "Неверный выбор. Повторите попытку." << endl;
        }

    } while (choice != 0);

    return 0;
}
