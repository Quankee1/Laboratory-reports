#include <iostream>
#include <clocale>
#include <list>
#include <algorithm>
using namespace std;

class Pair {
	int first;
	double second;
public:
	Pair() : first(0), second(0) {}
	Pair(int f, double s) : first(f), second(s) {}
	Pair(const Pair& p) {
		first = p.first;
		second = p.second;
	}
	~Pair() {}
	int getFirst() {
		return first;
	}
	double getSecond() {
		return second;
	}
	void setFirst(int f) {
		first = f;
	}
	void setSecond(double s) {
		second = s;
	}
	double sum() {
		return first + second;
	}
	Pair& operator=(const Pair& t) {
		if (&t == this) return *this;
		first = t.first;
		second = t.second;
		return *this;
	}
	Pair operator-(const Pair& p) {
		return Pair(first - p.first, second - p.second);
	}
	Pair operator+(int f) {
		return Pair(first + f, second);
	}
	Pair operator+(double s) {
		return Pair(first, first + s);
	}
	Pair& operator+=(double t) {
		second += t;
		return *this;
	}
	friend istream& operator>>(istream& in, Pair& t) {
		in >> t.first >> t.second;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Pair& t) {
		out << t.first << ':' << t.second;
		return out;
	}
	Pair& operator+=(const Pair& p) {
		first += p.first;
		second += p.second;
		return *this;
	}
	bool operator>(const Pair& other) const {
		return first > other.first || (first == other.first && second > other.second);
	}
	bool operator<(const Pair& other) const {
		return first < other.first || (first == other.first && second < other.second);
	}
};

typedef list<Pair> PList;

PList make_list(int n)
{
	Pair a;
	PList v;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите пару: ";
		cin >> a;
		v.push_back(a);
	}
	return v;
}

void print_list(PList v)
{
	for (PList::iterator it = v.begin(); it != v.end(); ++it)
		cout << it->getFirst() << " " << it->getSecond() << endl;
	cout << endl;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	PList v;
	v = make_list(n);
	print_list(v);

	Pair sum;
	for_each(v.begin(), v.end(), [&sum](Pair& p) { sum += p; });
	sum.setFirst(sum.getFirst() / v.size());
	sum.setSecond(sum.getSecond() / v.size());
	v.push_back(sum);
	print_list(v);
	Pair one;
	Pair two;

	cout << "Первая пара: ";
	cin >> one;
	cout << "Вторая пара: ";
	cin >> two;
	if (one > two)
		swap(one, two);
	list<Pair>::iterator s = remove_if(v.begin(), v.end(), [one, two](Pair& p) {return p > one && p < two; });
	v.erase(s, v.end());
	print_list(v);

	pair<list<Pair>::iterator, list<Pair>::iterator> stl_pair = minmax_element(v.begin(), v.end());
	cout << "Минимальный элемент: " << *stl_pair.first;
	cout << "Максимальный элемент: " << *stl_pair.second;
	double summ = stl_pair.first->sum() + stl_pair.second->sum();
	for_each(v.begin(), v.end(), [summ](Pair& p) {p += summ; });
	print_list(v);
	return 0;
}