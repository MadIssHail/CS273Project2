#include <iostream>
#include <list>
#include "Address.h"

void Sort(std::list<Address>& l1, std::list<Address>& l2);

void Merge(std::list<Address> l1, std::list<Address> l2);

void Unique(std::list<Address> l1);

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

	for (std::list<Address>::iterator it = l1.begin(); it != l1.end(); ++it)
	{
		std::cout << *it << "\n";
	}
	std::cout << "out";
	Sort(l1, l1);
	Sort(l1, l1);

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
		for (std::list<Address>::iterator it = l1.begin(); it != l1.end(); ++it)
		{
			std::cout << *it << "\n";
		}
	}
	std::cout << "out3" << "\n";
}

void Merge(std::list<Address> l1, std::list<Address> l2)
{
	while (!l2.empty())
	{
		l1.push_back(l2.front());
		l2.pop_back();
	}
}

void Unique(std::list<Address> l1)
{
	for (std::list<Address>::iterator it = l1.begin(); it != l1.end(); ++it)
	{
		for (std::list<Address>::iterator it2 = it; it2 != l1.end(); ++it2)
		{
			if (it == it2)
			{
				l1.erase(it2);
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