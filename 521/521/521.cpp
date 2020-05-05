// 521. 22. Для студентов заданной группы, имеющих средний балл, больший 4.5, вывести фамилию, имя, отчество и средний балл.
//
#include <iostream>
#include <cmath>
#include <string>
#include "time.h"


using namespace std;

class Student
{
public:
	string Group;
	string FullName;
	int Math;
	int English;
	int Programming;
	float Average()
	{
		return (Math + English + Programming) / 3;
	}
};

int main()
{
	Student students[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "Input fullname of "<< i + 1 <<"th student: ";
		cin >> students[i].FullName;
		cout << "Input group of student: ";
		cin >> students[i].Group;
		cout << "Input Math mark: ";
		cin >> students[i].Math;
		cout << "Input English mark: ";
		cin >> students[i].English;
		cout << "Input Programming mark: ";
		cin >> students[i].Programming;
	}

	string group;

	cout << "Input group of student: ";
	cin >> group;

	for (int i = 0; i < 3; i++)
	{
		if (group == students[i].Group && students[i].Average() > 4.5)
			cout << "Student with an average mark above 4.5: " << students[i].FullName << endl;
	}

	system("PAUSE");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
