#include <iostream>
#include <list>
using namespace std;

void fill_list(list<double>& lst) 
{
    int n;
    cout << "������� ���������� ���������: ";
    cin >> n;

    cout << "������� " << n << " ����� ���� double:\n";
    for (int i = 0; i < n; ++i) 
    {
        double num;
        cin >> num;
        lst.push_back(num);
    }
}

void add_average(list<double>& lst) 
{
    if (lst.empty())
    {
        cout << "������ ����!\n";
        return;
    }

    double sum = 0.0;
    for (const double& num : lst) 
    {
        sum += num;
    }
    double average = sum / lst.size();
    lst.push_back(average);

    cout << "������� �������������� (" << average << ") ��������� � �����.\n";
}

void remove_in_range(list<double>& lst, double min_val, double max_val) 
{
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it >= min_val && *it <= max_val) {
            it = lst.erase(it);
        }
        else {
            ++it;
        }
    }
}

void print_list(const list<double>& lst) 
{
    cout << "������: ";
    for (const double& num : lst) 
    {
        cout << num << " ";
    }
    cout << endl;
}

void add_min_max_sum(list<double>& lst) 
{
    if (lst.empty()) 
    {
        cout << "������ ����!\n";
        return;
    }

    double min_val = lst.front();
    double max_val = lst.front();

    for (const double& num : lst) 
    {
        if (num < min_val) min_val = num;
        if (num > max_val) max_val = num;
    }

    double sum = min_val + max_val;

    for (double& num : lst) 
    {
        num += sum;
    }

    cout << "� ������� �������� ��������� ����� min � max (" << sum << ")\n";
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    list<double> numbers;
    int choice;
    double min_val, max_val;

    do 
    {
        cout << "\n����:\n"
            << "1. ��������� ������\n"
            << "2. �������� ������� ��������������\n"
            << "3. ������� �������� � ���������\n"
            << "4. �������� ����� min � max � ������� ��������\n"
            << "5. ������� ������\n"
            << "0. �����\n"
            << "�������� ��������: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            numbers.clear();
            fill_list(numbers);
            break;
        case 2:
            add_average(numbers);
            break;
        case 3:
            cout << "������� �������� (min max): ";
            cin >> min_val >> max_val;
            remove_in_range(numbers, min_val, max_val);
            break;
        case 4:
            add_min_max_sum(numbers);
            break;
        case 5:
            print_list(numbers);
            break;
        case 0:
            cout << "�����...\n";
            break;
        default:
            cout << "�������� �����!\n";
        }
    } while (choice != 0);

    return 0;
}