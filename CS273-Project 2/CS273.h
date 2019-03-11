#ifndef _CS273_
#define _CS273_

namespace CS273 
{ 
	template <class T>
	class vector
	{
	private:
		int _size;
		int _capacity;
		T * _data;
		static const int INITIAL_CAPACITY = 5;
	public:
		vector<T>() : _capacity(INITIAL_CAPACITY), _data(new T[INITIAL_CAPACITY]), _size(0) { } //Book pg 240
		vector<T>(int capacity) : _capacity(capacity), _data(new T[capacity]), _size(0) { }
		vector<T>(const vector<T>& other) : _capacity(other._capacity), _size(other._size), _data(new T[other._capacity])
		{
			for (int i = 0; i < _size; i++)
			{
				_data[i] = other._data[i];
			}
		}
		~vector<T>();

		vector<T> operator=(const vector<T>& other);

		T& operator[](int index);

		T& at(int index);
		void resize(int n);
		int size();
		int capacity();

		void assign(int index, T element);

		void insert(int index, T element);


		void push_back(T element);
		void pop_back();
		void erase(int index);

		void swap(vector<T>& other);
	
	};
}

#endif
