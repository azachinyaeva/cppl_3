#include <iostream>
#include <string>
#include "Exception.h"

class smart_array
{
	int* A;
	int size;
	int i = 0;

public:
	smart_array(int size_)
	{
		size = size_;
		A = new int[size] {};
	}
	~smart_array()
	{
		delete[] A;
	}

	void add_element(int num)
	{
		if (i < size) {
			if (A[i] == 0)
			{
				A[i] = num;
				i++;
			}
			else
			{
				i++;
			}
		}
		else
		{
			throw ArrException("Добавление элемента невозможно: превышен размер массива \n");
		}
	}
	int get_element(int n)
	{
		if ((n >= 0) && (n < size))
		{
			return A[n];
		}
		else
		{
			throw ArrException("Отсутствует элемент " + std::to_string(n));
		}
	}
	smart_array& operator=(const smart_array &right) 
	{
		delete[] A;
		size = right.size;
		A = new int[size] {};
		for (int j = 0; j < size; j++)
		{
			A[i] = right.A[i];
		}
		return *this;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(1);
		arr.add_element(5);
		arr.add_element(1);
		arr.add_element(1);
		smart_array new_array(3);
		new_array.add_element(10);
		new_array.add_element(20);
		new_array.add_element(30);
		
		arr = new_array;
	}
	catch (const ArrException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
