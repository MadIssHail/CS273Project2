#include <iostream>
#include <list>
#include "Address.h"

// Sorts the elements of a list by state, city, then name. Utilizes the > operator
// PRE: Takes in a list with address elements
// POST: Returns a list sorted using overload operators
void Sort(std::list<Address>& l1, std::list<Address>& l2);

// Combines the data of two lists into the first
// PRE: Takes in two different lists
// POST: Returns one list, sorted
void Merge(std::list<Address>& l1, std::list<Address>& l2);

// Deletes duplicate elements in a list. Utilizes the = operator 
// PRE: Checks name, state, and city for equals conditions
// POST: A new list is returned, this time without duplicates
void Unique(std::list<Address>& l1);

// Function utilized in Sort to swap the data of two Addresses in the list
// PRE: Takes in two addresses
// POST: Returns the addresses in the correct list order
void swap(Address &a, Address &b);

// Overload ostream operator to returned the to_string() of our Address list
// PRE: Takes in an address being outputted to the compiler
// POST: Returns a formatted version of our member data
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
	Sort(l1, l2);
}

void Unique(std::list<Address>& l1)
{
	std::list<Address>::iterator it = ++l1.begin();
	for (std::list<Address>::iterator it2 = l1.begin(); it2 != --l1.end(); ++it2)
	{
		if (*it == *it2)
		{
			l1.erase(it2);
		}
		++it;
	}
} //////////

void swap(Address &a, Address &b)
{
	Address temp = a;
	a = b;
	b = temp;
}