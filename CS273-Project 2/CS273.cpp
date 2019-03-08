#include "CS273.h"
#include <iostream>

// Default constructor //
template <class T>
CS273::vector<T>::vector() 
{
	_capacity = 5;
	_size = 0;
	T* _data;
}

// Constructor with a given capacity //
template <class T>
CS273::vector<T>::vector(int capacity) {
	_capacity = capacity;
	_size = 0;
	T*_data = new T[_capacity];
}

// Copy constructor //
template <class T>
CS273::vector<T>::vector(const vector& v)
{
	_data[v._capacity];
	for (int i = 0; i < v._size; i++) 
	{
		_data[i] = v._data[i];
	}
	_size = v._size;
	_capacity = v._capacity;
}

// Destructor //
template <class T>
CS273::vector<T>::~vector()
{
  delete [] *_data;
}


template<class T>
T& CS273::vector<T>::operator=(vector other)
{
	swap(*this, other);
	return *this;
}

template<class T>
T & CS273::vector<T>::operator[](int index)
{
	return *_data[index];
}

template<class T>
T & CS273::vector<T>::at(int index)
{
	return *_data[index];
}



// What if n is negative? //
template <class T>
void CS273::vector<T>::resize(int n)
{
	T * new_data = new T[n];
	if (n > _size)
	{
		for (int i = 0; i < _size; i++) {
			new_data[i] = *_data[i];
		}
	}
	else if (n <= _size) 
	{
		for (int i = 0; i < n; i++) {
			new_data[i] = *_data[i];
		}
    _size = n;
	}
  // Error comes from delete [] _data, delete [] *_data compiles but causes a runtime error
  std::cout << "TESTING before delete[] *_data\n";
  delete [] *_data;
  std::cout << "TESTING after delete[] *_data\n";
  *_data = new_data;
	_capacity = n;
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
	*_data[index] = element;
}

template<class T>
void CS273::vector<T>::insert(int index, T element)
{
	if (_size == _capacity)
	{
		resize(_capacity * 2);
	}
	for (int i = index; i < _size; i++)
	{
		_data[i + 1] = _data[i];
	}
	_size++;
	*_data[index] = element;
}

template<class T>
void CS273::vector<T>::push_back(T element)
{
	if (_size == _capacity)
	{
    std::cout << "calling resize\n";
		resize(_capacity * 2 + 1);
	}
	_data[_size] = &element;
	_size++;
}



// What if index is negative? //
template <class T>
void CS273::vector<T>::erase(int index)
{
	for (int i = index; i < _size - 1; i++)
	{
		*_data[i] = *_data[i + 1];
	}
	_size--;
}

template <class T>
void CS273::vector<T>::pop_back()
{
	erase(_size - 1);
}


template<class T>
void CS273::vector<T>::swap(vector<T>& other)
{
	T * temp_data = _data;
	_data = other._data;
	other._data = temp_data;
  delete [] *temp_data;
}



// Test push_back by filling a vector with values //
void test_pb(){
  CS273::vector<int> v1;

  int value = 2;
  for (int i = 0; i < 20; i++){
    value += 5;
    std::cout << "i is currently " << i << "\n";
    
    v1.push_back(value);
    std::cout << v1[i] << std::endl;

  }
  std::cout<< "Done with loop" << std::endl;


}


int main() {
  test_pb();
  std::cout << "Testing function has been called\n";
	return 0;
}