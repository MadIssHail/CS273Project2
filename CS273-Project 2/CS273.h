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
		// Vector Constructors: create vectors when called by the test case
		// PRE: Default constructor takes no arguements
		// POST: Returns a vector with the specified data members
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

		// Overloads equals operator to override data in one vector with the data of a different vector
		// PRE: Must be called with two valid vectors
		// POST: The vector on the left side of the equals sign will now have the data of the vector on the right side of the argument
		vector<T> operator=(const vector<T>& other);

		// Overloads brackets in order to output a single element at a certain index
		// PRE: Checks for valid index in vector being outputted
		// POST: Returns the data at the index specified
		T& operator[](int index);

		// Works the same as the [] operator to output a singe element at a certain index
		// PRE: Checks for valid index in vector being outputted
		// POST: Returns the data at the index specified
		T& at(int index);
		
		// Creates a new vector of capacity n and copies the elements of the vector being resized into the new vector
		// PRE: Checks if n is a valid, positive integer ////////////////////////////////
		// POST: Creates a new vector of capacity n with the same elements as the vector being resized
		void resize(int n);

		// Returns the size of the specified vector
		// PRE: Verifies the vector being checked exists (complier handled)
		// POST: Returns the size of the specfied vector
		int size();

		// Returns the capacity of the specified vector
		// PRE: Verifies the vector being check exists (compiler handled)
		// POST: Returns the capacity of the specified vector
		int capacity();

		// Takes in an index, and replaces the element at that index in the specified vector with a new element
		// PRE: Checks to make sure the index is valid
		// POST: The vector at index now has a new specified element
		void assign(int index, T element);


		void insert(int index, T element);


		void push_back(T element);
		void pop_back();
		void erase(int index);

		void swap(vector<T>& other);
	
	};
}

#endif
