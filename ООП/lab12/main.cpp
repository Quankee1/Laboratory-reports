#include <iostream>
#include <set>
using namespace std;

void printMultiset(const multiset<double>& ms) 
{
    for (const auto& item : ms) 
    {
        cout << item << " ";
    }
    cout << endl;
}

void addAverage(multiset<double>& ms) 
{
    if (ms.empty()) return;

    double sum = 0.0;
    for (const auto& item : ms) 
    {
        sum += item;
    }
    double average = sum / ms.size();
    ms.insert(average);

    cout << "Added average: " << average << endl;
}

void removeInRange(multiset<double>& ms, double a, double b) 
{
    auto it = ms.begin();
    while (it != ms.end()) {
        if (*it >= a && *it <= b) 
        {
            it = ms.erase(it);
        }
        else 
        {
            ++it;
        }
    }

    cout << "Removed elements in range [" << a << ", " << b << "]" << endl;
}

void addMinMaxSum(multiset<double>& ms)
{
    if (ms.empty()) return;

    double min_val = *ms.begin();
    double max_val = *ms.rbegin();
    double sum = min_val + max_val;

    multiset<double> temp;
    for (const auto& item : ms)
    {
        temp.insert(item + sum);
    }

    ms = temp;

    cout << "Added sum of min(" << min_val << ") and max("
        << max_val << "): " << sum << " to each element" << endl;
}

int main() 
{
    multiset<double> numbers = { 1.5, 2.3, 4.1, 2.3, 5.7, 2.3, 6.4 };

    cout << "Original multiset: ";
    printMultiset(numbers);

    addAverage(numbers);
    cout << "After adding average: ";
    printMultiset(numbers);

    removeInRange(numbers, 2.0, 4.0);
    cout << "After removing [2.0, 4.0]: ";
    printMultiset(numbers);

    addMinMaxSum(numbers);
    cout << "Final multiset: ";
    printMultiset(numbers);

    return 0;
}