// 22. Дана квадратная матрица. Если номер стобца с максимальной суммой элементов совпадает с номером строки
// с максимальной суммой элементов, определить сумму найденных элементов строки и столбца, иначе распечатать 
// номера найденных строки и столбца с найдеными суммами.
//

#include <iostream>
#include <cmath>
#include <string>
#include "time.h"


using namespace std;

class MatrixParameters
{
public:
	int Position;
	int Sum;

	MatrixParameters()
	{
		Position = 0;
		Sum = INT_MIN;
	}
};

class CalculateMatrix
{
public:
	void InitMatrix(float** Array, int n)
	{
		srand(time(0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Array[i][j] = rand() % 10;// -10;
				cout << Array[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	void PrintMatrix(float** Array, int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << Array[i][j] << "\t";
			}
			cout << endl;
		}
	}

	MatrixParameters SearchMaxIndex(float** Array, int n, bool isRaw = true)
	{
		int sum = 0;
		MatrixParameters param;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sum += isRaw ? Array[i][j] : Array[j][i];
			}
			
			if (param.Sum < sum)
			{
				param.Sum = sum;
				param.Position = i;
			}

			sum = 0;
		}

		return param;
	}
};

int main()
{
	int row;
	CalculateMatrix calc;

	cout << "Enter the size of matrix: ";
	cin >> row;

	float** Array = new float* [row];

	for (int i = 0; i < row; i++)
	{
		Array[i] = new float[row];
	}

	calc.InitMatrix(Array, row);

	MatrixParameters param1, param2;
	param1 = calc.SearchMaxIndex(Array, row);
	param2 = calc.SearchMaxIndex(Array, row, false);

	if (param1.Position == param2.Position)
	{
		cout << "Summ of max column and max row:" << param1.Sum + param2.Sum;
	}
	else
	{
		cout << "Max column index: " << param2.Position << ". Max column summ: " << param2.Sum << endl;
		cout << "Max row index: " << param1.Position << ". Max row summ: " << param1.Sum << endl;
	}

	system("Pause");
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
