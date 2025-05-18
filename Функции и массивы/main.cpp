#include <iostream>
#include <clocale>
using namespace std;

// ������� ��� ��������� ���������������� ���������� �������
void dA(int a[],int m_vost[][3], int row, int col)
{
	
	for (int i = 0; i < row * col; i += col)
	{
		for (int j = row * col; j < row * col * 2; j++)
		{
			if (a[i] == a[j])
			{
				int g = (j - row * col) % col; // ������� ������ ������
				for (int k = 0; k < col; k++)
					m_vost[g][k] = a[k + i];
			}
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << m_vost[i][j] << ' ';

		cout << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "Russian");

	const int row = 3, column = 3; 
	int m_vost[row][column]; 

	// ���������� ������, �������  ������ � ������������ �������, ����� �������
	int a[row * column * 2] = {41,50,6,100,2,3,77,8,0,2,50,8,100,41,77,3,6,0};
	cout << "�������� ����������� �������:" << endl;
	for (int i = 0; i < row * column * 2; i++)
		cout << a[i] << ' ';
	cout << endl;

	cout << "��������������� ��������� ������:" << endl;
	dA(a, m_vost, row, column);

	return 0;
}