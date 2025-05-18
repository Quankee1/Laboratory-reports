#include "Pay.h"
using namespace std;

void print(Pay& obj)
{
	cout << "Значение полей объекта: " << endl;
	cout << "fio = " << obj.get_fio() << endl;
	cout << "salary = " << obj.get_salary() << endl;
	cout << "prize = " << obj.get_prize() << endl << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	Pay obj1; // Вызов конструктора без параметров
	print(obj1);

	Pay obj2("Молочко Артём Анатольевич", 100, 10); // Вызов конструктора с параметрами
	print(obj2);

	Pay obj3(obj2); // Вызов конструктора копирования
	print(obj3);

	// Меняем значения полей с помощью метода set_data
	obj3.set_data("Иванов Иван Иванович", 52, 49);
	print(obj3);
}