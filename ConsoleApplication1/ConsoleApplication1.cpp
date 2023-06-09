﻿#include <iostream>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");


	cout << "Сортировка вставками" << endl;

	int N;
	cout << "Введите кол-во элементов массива" << endl;
	cin >> N;

	int* a=new int[N]; 

	cout << "Введите элементы массива" << endl;

	for (int i = 1; i < N+1; i++)
	{
		cin >> a[i];
	}

	int buff = 0; // для хранения перемещаемого значения
	int i, j; // для циклов 

	/************* Начало сортировки *******************/
	for (i = 1; i < N+1; i++)
	{
		buff = a[i]; // запомним обрабатываемый элемент
		// и начнем перемещение элементов слева от него
		// пока запомненный не окажется меньше чем перемещаемый
		for (j = i - 1; j >= 0 && a[j] > buff; j--)
			a[j + 1] = a[j];

		a[j + 1] = buff; // и поставим запомненный на его новое место 
	}
	/************* Конец сортировки *******************/

	for (int i = 1; i < N+1; i++) // вывод отсортированного массива
		cout << a[i] << '\t';
	cout << endl;




	cout << "Сортировка выбором" << endl;
	int M;
	
	int min = 0;	// для записи минимального значения
	int buf = 0;	// для обмена значениями 

	cout << "Введите кол-во элементов" << endl;
	cin >> M;

	int* arr = new int[M];

	cout << "Введите элементы массива" << endl;

	for (int i = 1; i < M+1; i++)
	{
		cin >> arr[i];
	}

 
	for (int i = 0; i < M+1; i++)
	{
		min = i; // запомним номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < M+1; j++)
			min = (arr[j] < arr[min]) ? j : min;
		// cделаем перестановку этого элемента, поменяв его местами с текущим
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}
	/*********** Конец сортировки **************/
	cout << "Отсортированный массив" << endl;
	for (int i = 1; i < M+1; i++) 	//Вывод отсортированного массива
	{
		cout << arr[i] << '\t';
		cout << endl;
	}
 
}