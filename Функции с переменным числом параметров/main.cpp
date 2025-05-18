#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double Distance(int x1, ...)
{
	int* p = &x1;  
	int y1 = *(p+2);  
	int x2 = *(p+4);  
	int y2 = *(p+6);  

	// Вычисляем расстояние
	double result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return result;
}

double square(double a, ...)
{
	double* p = &a;
	double b = *(p + 1);
	double c = *(p + 2);
	double pp = (a + b + c) / 2;    // полупериметр 

	double result = sqrt(pp * (pp - a) * (pp - b) * (pp - c));
	return result;
}

double square1(int n, int x1, ...) 
{

	// Найти самую длинную диагональ
	double max_d = 0;
	int max_x1 = 0, max_y1 = 0, max_x2 = 0, max_y2 = 0;
	int* p = &x1;
	for (int i = 0; i < n * 4; i += 4)
	{
		int xi = *(p + i);       // x-координата текущей точки
		int yi = *(p + i + 2);   // y-координата текущей точки

		for (int j = i + 4; j < n * 4; j += 4)
		{
			int xj = *(p + j);   // x-координата следующей точки
			int yj = *(p+j+2); // y-координата следующей точки

			double current_d = Distance(xi, yi, xj, yj);
			if (current_d > max_d)  // Проверяем какая диагональ больше, на предыдущем шаге или текущая
			{
				max_d = current_d;
				max_x1 = xi;
				max_y1 = yi;
				max_x2 = xj;
				max_y2 = yj;
			}
		}

	}
	// Найти площадь треугольников
	double max_area = 0;
	for (int i = 0; i < n * 4; i += 4)
	{
		int xi = *(p+i);
		int yi = *(p + i+2);

		// Проверка на совпадение с точками диагонали
		bool flag = (xi == max_x1 && yi == max_y1) || (xi == max_x2 && yi == max_y2);
		if (flag == false)
		{
			double side1 = Distance(max_x1, max_y1, max_x2, max_y2);
			double side2 = Distance(max_x1, max_y1, xi, yi);
			double side3 = Distance(max_x2, max_y2, xi, yi);
			double area = square(side1, side2, side3);

			if (area > max_area) // Проверяем какая площадь больше, посчитанная на текущем шаге, или прошлая
				max_area = area;
		}
	}
	return max_area;
	
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int x1, y1, x2, y2, x3, y3;
	cout << "Введите координаты двух точек (x,y) через пробел: ";
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "Расстояние между двумя точками = " << Distance(x1, y1, x2, y2) << endl;

	cout << "Введите координаты трех точек (x,y) через пробел: ";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	// Стороны треугольника
	double st1 = Distance(x1, y1, x2, y2);
	double st2 = Distance(x2, y2, x3, y3);
	double st3 = Distance(x3, y3, x1, y1);
	cout << "Площадь треугольника по вершинам = " << square(st1,st2,st3) << endl;

	// Вызов функции для вычисления площади треугольника с наибольшей диагональю
	double area =  square1(5, 1,1, 5,1,6,4,3,6, 0, 4); 
	cout << "Площадь треугольника с наибольшей диагональю: " << area << endl;

	return 0;
}