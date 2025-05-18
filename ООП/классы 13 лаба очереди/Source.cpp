#include <iostream>
#include <clocale>
#include <queue>
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

typedef priority_queue<Pair> PQueue;

PQueue make_queue(int n)
{
	Pair a;
	PQueue v;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите пару: ";
		cin >> a;
		v.push(a);
	}
	return v;
}

void print_queue(PQueue v)
{
	while (!v.empty()) {
		Pair p = v.top();
		cout << p << endl;
		v.pop();
	}
	cout << endl;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	PQueue v;
	v = make_queue(n);
	print_queue(v);

	Pair sum;
	PQueue t = v;
	while (!t.empty()) {
		sum += t.top();
		t.pop();
	}
	sum.setFirst(sum.getFirst() / v.size());
	sum.setSecond(sum.getSecond() / v.size());
	v.push(sum);
	print_queue(v);

	Pair one;
	Pair two;

	cout << "Первая пара: ";
	cin >> one;
	cout << "Вторая пара: ";
	cin >> two;
	if (one > two)
		swap(one, two);
	PQueue filtered;
	while (!v.empty()) {
		Pair p = v.top();
		if (!(p > one && p < two)) {
			filtered.push(p);  
		}
		v.pop();
	}
	v = filtered;
	print_queue(v);

	Pair minElem = v.top();
	Pair maxElem = minElem;

	PQueue p = v;
	while (!v.empty()) {
		Pair current = v.top();
		if (current < minElem) {
			minElem = current;
		}
		v.pop();
	}
	v = p;
	cout << "Минимальный элемент: " << minElem << endl;
	cout << "Максимальный элемент: " << maxElem << endl;

	// Суммируем минимальный и максимальный элементы
	double summ = minElem.sum() + maxElem.sum();

	// Добавляем эту сумму ко всем элементам
	PQueue newq;
	PQueue temp = v;
	while (!temp.empty()) {
		Pair p = temp.top();
		p += summ;
		newq.push(p);
		temp.pop();
	}

	v = newq;
	print_queue(v);
	return 0;
}