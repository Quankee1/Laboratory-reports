#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

double f(double x) {
    return x - 2 + sin(1 / x);
}

double f1(double x) {
    return 1 - cos(1 / x) / pow(x, 2);
}

double f2(double x) {
    return 2 * cos(1 / x) / pow(x, 3) - sin(1 / x) / pow(x, 4);
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, x0, x, e;
    cin >> a >> b >> e;

    if (f(a) * f2(a) > 0) {
        x0 = a;
    } else if (f(b) * f2(b) > 0) {
        x0 = b;
    } else {
        cout << "Неправильно введён интервал";
        return 0;
    }

    x = x0 - f(x0) / f1(x0);
    while (abs(x - x0) > e) {
        x0 = x;
        x = x0 - f(x0) / f1(x0);
    }

    cout << x;
    return 0;
}
