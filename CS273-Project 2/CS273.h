#ifndef _CS273_H_
#define _CS273_H_

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
		// Default constructor creates a default vector
		// PRE: Default constructor takes no arguements
		// POST: Creates a vector with the specified data members
		vector<T>() : _capacity(INITIAL_CAPACITY), _data(new T[INITIAL_CAPACITY]), _size(0) { } //We found these definitions in the course textbook on page 240
		
		// Constructor takes a capacity and creates a vector
		// PRE: Checks if the capacity given is a vaild number
		// POST: Cretes a vector with the specified data members
		vector<T>(int capacity) : _capacity(capacity), _data(new T[capacity]), _size(0) { if (capacity > 0) { _capacity = capacity; } }
		
		// Copy constructor does a deep copy fromm one vector to another
		// PRE: Takes in two vectors
		// POST: Both vectors should have the same data
		vector<T>(const vector<T>& other) : _capacity(other._capacity), _size(other._size), _data(new T[other._capacity])
		{
			for (int i = 0; i < _size; i++)
			{
				_data[i] = other._data[i];
			}
		}

		// Destructor
		// PRE: Applied to a vector
		// POST: Deletes vector data
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
		// PRE: Verifies the vector being checked exists (compiler handled)
		// POST: Returns the capacity of the specified vector
		int capacity();

		// Takes in an index and replaces the element at that index in the specified vector with a new element
		// PRE: Checks to make sure the index is valid
		// POST: The vector at index now has a new specified element
		void assign(int index, T element);

		// Takes in an index and inserts a new element at that index, pushing all the other values in the vector behind it back 1
		// PRE: Checks to make sure the index is valid
		// POST: The vector at index now has a new specified element and size++
		void insert(int index, T element);

		// Adds a new element to the back of a vector and resizes if necessary
		// PRE: Checks if the vector is large enough to handle the push_back
		// POST: Adds a new element to the vector, size++
		void push_back(T element);

		// Erases the last element of the specified vector
		// PRE: Checks if the vector has elements or not
		// POST: Erases the last element of a vector, size--
		void pop_back();

		// Erases the element of a vector at a specified index
		// PRE: Checks to make sure the index is valid
		// POST: Erases at the desired index and moves the rest of the vector behind that index forward, size--
		void erase(int index);

		// Swaps the contents, sizes, and capacities of two desired vectors
		// PRE: Two vectors necessary
		// POST: Vector contents are interchanged
		void swap(vector<T>& other);
	
	};
}

#endif