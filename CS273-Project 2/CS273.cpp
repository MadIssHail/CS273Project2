#include "CS273.h"

template <class T>
CS273::vector<T>::vector() 
{
	_capacity = 5;
	_size = 0;

	template <class T>
	T* _data = new T[_capacity];
}

template <class T>
CS273::vector<T>::vector(int capacity) {
	_capacity = capacity;
	_size = 0;
	T* _data = new T[_capacity];
}

template <class T>
CS273::vector<T>::vector(const vector& v)
{
	this._data[v._capacity];
	for (int i = 0; i < v._size; i++) 
	{
		this._data[i] = v._data[i];
	}
	_size = v._size;
	_capacity = v._capacity;
}

template <class T>
CS273::vector<T>::~vector()
{
	delete[] _data;
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
	return _data[index];
}

template<class T>
T & CS273::vector<T>::at(int index)
{
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
	if (_size == _capacity)
	{
		resize(_capacity * 2);
	}
	for (int i = index; i < _size; i++)
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
	_data[size] = element;
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
	T * temp_data = _data;
	_data = other._data;
	other._data = temp_data;
}

int main() {
	return 0;
}