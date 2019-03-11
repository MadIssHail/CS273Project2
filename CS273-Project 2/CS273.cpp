#include "CS273.h"
#include <iostream>

template <class T>
CS273::vector<T>::~vector()
{
	delete[] _data;
}


template<class T>
CS273::vector<T> CS273::vector<T>::operator=(const vector<T>& other)
{
	std::cout << "= flag 0" << "\n";
	vector<T> _other(other);
	swap(_other);
	std::cout << "= flag 1" << "\n";
	return *this;
}

template<class T>
T& CS273::vector<T>::operator[](int index)
{
	if (index < 0 || index > _size)
	{
		throw std::out_of_range
		("index to operator[] out of range");
	}
	return _data[index];
}

template<class T>
T& CS273::vector<T>::at(int index)
{
	if (index < 0 || index > _size)
	{
		throw std::out_of_range
		("index to at() out of range");
	}
	return _data[index];
}

template <class T>
void CS273::vector<T>::resize(int n)
{
	T * new_data = new T[n];
	if (n > _size)
	{
		for (int i = 0; i < _size; i++) {
			new_data[i] = _data[i];
		}
		delete[] _data;
		_data = new_data;
		_capacity = n;
		std::cout << "resize 1" << std::endl;
	}
		else if (n <= _size) 
		{
			for (int i = 0; i < n; i++) {
				new_data[i] = _data[i];
			}
			delete[] _data;
			_data = new_data;
			_capacity = n;
			_size = n;
			std::cout << "resize 2" << std::endl;
		}

}

template <class T>
int CS273::vector<T>::size()
{
	return _size;
}

template <class T>
int CS273::vector<T>::capacity()
{
	return _capacity;
}

template<class T>
void CS273::vector<T>::assign(int index, T element)
{
	_data[index] = element;
}

template<class T>
void CS273::vector<T>::insert(int index, T element)
{
	if (index < 0 || index > _size)
	{
		throw std::out_of_range
		("index to insert() out of range");
	}
	if (_size == _capacity)
	{
		resize(_capacity * 2);
	}
	for (int i = _size - 1; i >= index; i--)
	{
		_data[i + 1] = _data[i];
	}
	_size++;
	_data[index] = element;
}

template<class T>
void CS273::vector<T>::push_back(T element)
{
	if (_size == _capacity)
	{
		resize(_capacity * 2);
	}
	_data[_size] =  element;
	_size++;
}

template <class T>
void CS273::vector<T>::pop_back()
{
	erase(_size - 1);
}

template <class T>
void CS273::vector<T>::erase(int index)
{
	if (index < 0 || index > _size)
	{
		throw std::out_of_range
		("index to erase() out of range");
	}
	for (int i = index; i < _size - 1; i++)
	{
		_data[i] = _data[i + 1];
	}
	_data[_size - 1] = NULL;
	_size--;
}

template<class T>
void CS273::vector<T>::swap(vector<T>& other)
{
	std::cout << "swap flag 1" << "\n";
	T * temp_data = _data;
	T temp_size = _size;
	T temp_capacity = _capacity;
	_data = other._data;
	_size = other._size;
	_capacity = other._capacity;
	other._data = temp_data;
	other._size = temp_size;
	other._capacity = temp_capacity;
	std::cout << "swap flag 2" << "\n";
	delete[] temp_data;
	std::cout << "swap flag 3" << "\n";
}

template <class T>
void function(CS273::vector<T> v) 
{

}

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
		int value = 2*i;
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