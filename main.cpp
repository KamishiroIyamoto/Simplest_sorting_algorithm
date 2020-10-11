#include<iostream>
using namespace std;

void Add(int*& arr, int& size) // Добавляем ячейку в массив
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];
	delete[] arr;
	arr = temp;
	size++;
}

void Del(int*& arr, int& size, int count) // Убираем из массива выбранное число
{
	int* temp = new int[size - 1];
	bool a = false;
	for (int i = 0; i < size; i++)
	{
		if (a)
			temp[i - 1] = arr[i];
		else
		{
			if (arr[i] == count)
			{
				a = true;
				continue;
			}
			temp[i] = arr[i];
		}
	}
	delete[] arr;
	arr = temp;
	size--;
}

int main() // вводи int числа, для завершения введи 0
{
	int size = 1;
	int* first = new int[size];

	for (int i = 0; i < i + 1; i++)
	{
		cin >> first[i];
		if (first[i] == 0)
			break;
		Add(first, size);
	}

	system("cls");
	for (int i = 0; i < size; i++)
		cout << first[i] << '\t';

	int* temp = new int[--size];
	int min, size2 = size;
	for (int i = 0; i < size; i++)
	{
		min = first[0];
		for (int j = 0; j < size2; j++)
			if (first[j] < min)
				min = first[j];
		for (int j = 0; j < size2; j++)
			if (first[j] == min)
				Del(first, size2, min);
		temp[i] = min;
	}

	cout << endl;
	for (int i = 0; i < size; i++)
		cout << temp[i] << '\t';

	delete[] first, temp;
	return 0;
}