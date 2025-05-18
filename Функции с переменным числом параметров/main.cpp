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

	// ��������� ����������
	double result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return result;
}

double square(double a, ...)
{
	double* p = &a;
	double b = *(p + 1);
	double c = *(p + 2);
	double pp = (a + b + c) / 2;    // ������������ 

	double result = sqrt(pp * (pp - a) * (pp - b) * (pp - c));
	return result;
}

double square1(int n, int x1, ...) 
{

	// ����� ����� ������� ���������
	double max_d = 0;
	int max_x1 = 0, max_y1 = 0, max_x2 = 0, max_y2 = 0;
	int* p = &x1;
	for (int i = 0; i < n * 4; i += 4)
	{
		int xi = *(p + i);       // x-���������� ������� �����
		int yi = *(p + i + 2);   // y-���������� ������� �����

		for (int j = i + 4; j < n * 4; j += 4)
		{
			int xj = *(p + j);   // x-���������� ��������� �����
			int yj = *(p+j+2); // y-���������� ��������� �����

			double current_d = Distance(xi, yi, xj, yj);
			if (current_d > max_d)  // ��������� ����� ��������� ������, �� ���������� ���� ��� �������
			{
				max_d = current_d;
				max_x1 = xi;
				max_y1 = yi;
				max_x2 = xj;
				max_y2 = yj;
			}
		}

	}
	// ����� ������� �������������
	double max_area = 0;
	for (int i = 0; i < n * 4; i += 4)
	{
		int xi = *(p+i);
		int yi = *(p + i+2);

		// �������� �� ���������� � ������� ���������
		bool flag = (xi == max_x1 && yi == max_y1) || (xi == max_x2 && yi == max_y2);
		if (flag == false)
		{
			double side1 = Distance(max_x1, max_y1, max_x2, max_y2);
			double side2 = Distance(max_x1, max_y1, xi, yi);
			double side3 = Distance(max_x2, max_y2, xi, yi);
			double area = square(side1, side2, side3);

			if (area > max_area) // ��������� ����� ������� ������, ����������� �� ������� ����, ��� �������
				max_area = area;
		}
	}
	return max_area;
	
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int x1, y1, x2, y2, x3, y3;
	cout << "������� ���������� ���� ����� (x,y) ����� ������: ";
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "���������� ����� ����� ������� = " << Distance(x1, y1, x2, y2) << endl;

	cout << "������� ���������� ���� ����� (x,y) ����� ������: ";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	// ������� ������������
	double st1 = Distance(x1, y1, x2, y2);
	double st2 = Distance(x2, y2, x3, y3);
	double st3 = Distance(x3, y3, x1, y1);
	cout << "������� ������������ �� �������� = " << square(st1,st2,st3) << endl;

	// ����� ������� ��� ���������� ������� ������������ � ���������� ����������
	double area =  square1(5, 1,1, 5,1,6,4,3,6, 0, 4); 
	cout << "������� ������������ � ���������� ����������: " << area << endl;

	return 0;
}