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
		T * _data[];

  public:
		vector<T>();
		vector<T>(int capacity);
		vector<T>(const vector& v);
		~vector<T>();

		T& operator=(vector other);
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
