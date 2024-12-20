#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

double phi(double x) {
    return 2 - sin(1.0 / x);
}

double phi_pr(double x) {
    return cos(1.0 / x) / (x * x);
}

int main() {
    setlocale(LC_ALL, "Russian");

    double a = 1.0, b = 2.0; 
    double epsilon = 0.000001; 
    double x0 = 1.5; 

    
    bool sh = true; 
    for (double x = a; x <= b; x += 0.01) 
    {
        if (abs(phi_pr(x)) >= 1) 
        {
            sh = false;
        }
    }

    if (sh) 
    {
    double x_next = phi(x0);
    while (abs(x_next - x0) > epsilon) {
        x0 = x_next;
        x_next = phi(x0);
    }

    cout << "Приближенное значение корня: " << x_next << endl;
    
    } 
    else 
        cout << "Условие сходимости не выполнено " << endl;

    return 0;
}
