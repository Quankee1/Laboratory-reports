#include <iostream>
#include <clocale>
#include <map>
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

typedef map<int, Pair> Pmap;

Pmap make_map(int n)
{
	Pair a;
	Pmap v;
	
	for (int i = 0; i < n; i++)
	{
		cout << "Введите пару: ";
		cin >> a;
		v.insert((make_pair(i, a)));
	}
	return v;
}

void print_map(Pmap v)
{
	for (Pmap::iterator it = v.begin(); it != v.end(); ++it)
		cout << it->second.getFirst() << " " << it->second.getSecond() << endl;
	cout << endl;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	Pmap v;
	v = make_map(n);
	print_map(v);

	Pair sum;
	for (auto it = v.begin(); it != v.end(); ++it) {
		sum += it->second;
	}
	sum.setFirst(sum.getFirst() / v.size());
	sum.setSecond(sum.getSecond() / v.size());
	v.insert(make_pair(v.size(), sum));
	print_map(v);

	Pair one;
	Pair two;
	cout << "Первая пара: ";
	cin >> one;
	cout << "Вторая пара: ";
	cin >> two;
	if (one > two)
		swap(one, two);
	Pmap filtered;
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (!(it->second > one && it->second < two)) {
			filtered.insert(*it);
		}
	}
	v = filtered;
	print_map(v);

	auto minElem = v.begin();
	auto maxElem = minElem;
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (it->second < minElem->second) {
			minElem = it;
		}
		if (it->second > maxElem->second) {
			maxElem = it;
		}
	}
	cout << "Минимальный элемент: " << minElem->second << endl;
	cout << "Максимальный элемент: " << maxElem->second << endl;
	double summ = minElem->second.sum() + maxElem->second.sum();
	Pmap newMap;
	for (auto it = v.begin(); it != v.end(); ++it) {
		Pair updatedPair = it->second;  
		updatedPair += summ; 
		newMap.insert(make_pair(it->first, updatedPair));  
	}
	v = newMap;  
	print_map(v);  

	return 0;
}