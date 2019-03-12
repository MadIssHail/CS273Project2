#include <iostream>
#include <list>
#include "Address.h"

void Sort(std::list<Address>& l1, std::list<Address>& l2);

void Merge(std::list<Address>& l1, std::list<Address>& l2);

void Unique(std::list<Address>& l1);

void swap(Address &a, Address &b);


std::ostream & operator<<(std::ostream & os, Address c)
{
	os << c.to_string();
	return os;
};

int main() 
{
	std::list<Address> l1;
	std::list<Address> l2;

	l1.push_back(Address("Jen Eric", "Whitworth Dr", "spokane", "WA", 99251, "jeneric@gmail.com"));
	l1.push_back(Address("Jon Eric", "Whitworth Dr", "spokane", "WA", 99251, "joneric@gmail.com"));
	l1.push_back(Address("Jan Eric", "Whitworth Dr", "spokane", "CA", 99251, "janeric@gmail.com"));
	l1.push_back(Address("Jun Eric", "Whitworth Dr", "vancouver", "WA", 99251, "juneric@gmail.com"));
	l1.push_back(Address("Jen Eric", "Whitworth Dr", "spokane", "WA", 99251, "jeneric1gmail.com"));

	l2.push_back(Address("Jen Eric", "Whitworth Dr", "spokane", "WA", 99251, "jeneric@gmail.com"));
	l2.push_back(Address("Eric Jen", "Whitworth Dr", "spokane", "WA", 99251, "ericjen@gmail.com"));
	l2.push_back(Address("Eric Jen", "Whitworth Dr", "seattle", "WA", 99251, "ericjen2@gmail.com"));
	l2.push_back(Address("Eric Jen", "Whitworth Dr", "spokane", "CA", 99251, "ericjen3@gmail.com"));

	Sort(l1, l1);

	for (std::list<Address>::iterator it = l1.begin(); it != l1.end(); ++it)
	{
		std::cout << *it << "\n";
	}

	std::cout << "Merge" << "\n";
	Merge(l1, l2);

	for (std::list<Address>::iterator it = l1.begin(); it != l1.end(); ++it)
	{
		std::cout << *it << "\n";
	}

	//Sort(l1, l1);
	std::cout << "Unique" << "\n";
	Unique(l1);

	for (std::list<Address>::iterator it = l1.begin(); it != l1.end(); ++it)
	{
		std::cout << *it << "\n";
	}
}

void Sort(std::list<Address>& l1, std::list<Address>& l2)
{ 
	bool sorted = false;
	std::list<Address>::iterator it;
	std::cout << "out1";

	while (!sorted)
	{
		sorted = true;
		for (it = l1.begin(); it != --l1.end(); ++it)
		{
			std::list<Address>::iterator id = ++it;
			--it;
			if (*it > *id)
			{
				swap(*it, *id);
				sorted = false;
			}
		}
	}
	std::cout << "out3" << "\n";
}

void Merge(std::list<Address>& l1, std::list<Address>& l2)
{
	while (!l2.empty())
	{
		l1.push_back(l2.front());
		l2.pop_front();
	}
}

void Unique(std::list<Address>& l1)
{
	bool duplicates = true;
	std::list<Address>::iterator a;
	std::list<Address>::iterator b;

	while (duplicates)
	{
		duplicates = false;
		for (a = l1.begin(); a != --l1.end(); ++a)
		{
			b = ++a;
			--a;
			while(b != l1.end()) {
				if (*a == *b)
				{
					l1.erase(b);
					duplicates = true;
					
				}
				++b;
			}
		}
	}
}

void swap(Address &a, Address &b)
{
	Address temp = a;
	a = b;
	b = temp;
}