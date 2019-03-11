#include "CS273.h"
#include <iostream>

template <class T>
void function(CS273::vector<T> v) { }


int main()
{
	// Create a vector using default constructor //
	CS273::vector<int> v1;
	// Create a vector with an initial capacity //
	CS273::vector<int> v2(15);
	// Create a vector with a data type other than int //
	CS273::vector<char> v3;

	// Fill first vector (which should have initial vector capactiy of 5) with 10 elements to show that push_back works and capacity is dynamic //
	for (int i = 0; i < 10; i++) {
		std::cout << "i = " << i << "\n";
		int value = 2 * i;
		v1.push_back(value);
		std::cout << "vector size is now " << v1.size() << "\n";
		std::cout << "vector capacity is now " << v1.capacity() << "\n";
		std::cout << "vector[" << i << "] is " << v1[i] << "\n";
	}

	v1.assign(0, 57);
	std::cout << "The first element of v1 is " << v1.at(0) << "\n";

	for (int i = 0; i < 3; i++)
	{
		v1.pop_back();
	}
	v1.insert(3, 35);

	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << "vector[" << i << "] is " << v1[i] << "\n";
	}
	std::cout << "vector v1 size is now " << v1.size() << "\n";

	v1.erase(0);
	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << "vector[" << i << "] is " << v1[i] << "\n";
	}
	std::cout << "vector v1 size is now " << v1.size() << "\n";

	for (int i = 0; i < 15; i++) {
		std::cout << "i = " << i << "\n";
		int value2 = 3 * i;
		v2.push_back(value2);
		std::cout << "vector size is now " << v2.size() << "\n";
		std::cout << "vector capacity is now " << v2.capacity() << "\n";
		std::cout << "vector[" << i << "] is " << v2[i] << "\n";
	}

	v1.swap(v2);

	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << "vector[" << i << "] is " << v1[i] << "\n";
	}

	function(v1);

	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << "vector[" << i << "] is " << v1[i] << "\n";
	}

	std::cout << "= operator" << "\n";

	v1 = v2;
	std::cout << "= flag 2" << "\n";
	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << "vector[" << i << "] is " << v1[i] << "\n";
	}


	std::cout << "1111";
	return 0;
}

