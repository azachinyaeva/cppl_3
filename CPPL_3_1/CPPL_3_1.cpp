#include <iostream>
#include <string>
#include "Exception.h"

class smart_array
{
	int *A;
	int size;
	int i = 0;
	
public:
	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;
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
		if (i < size) 
		{
				A[i] = num;
				i++;
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
		std::cout << arr.get_element(12) << std::endl;
	}
	catch (const ArrException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
