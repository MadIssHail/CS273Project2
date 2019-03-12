#ifndef _ADDRESS_H_
#define _ADDRESS_H_
#include <string>
#include <iostream>

class Address {

private:
	std::string _street;
	int _postalCode;
	std::string _city;
	std::string _state;
	std::string _name;
	std::string _email;
public:

	Address() 
	{
		_name = "Jen Eric";
		_street = "Whitworth Dr";
		_city = "Spokane";
		_state = "WA";
		_postalCode = 99251;
		_email = "jeneric@gmail.com";
	}

	Address(std::string name, std::string street, std::string city, std::string state, int pc, std::string email)
	{
		_name = name;
		_street = street;
		_city = city;
		_state = state;

		if (pc > 10000 && pc < 99999)
		_postalCode = pc;
		_email = email;
	}

	std::string to_string() {
		return _name + " / " + _street + " " + _city + " " + _state + ", " + std::to_string(_postalCode) + ", " + _email;
	}

	bool operator>(const Address& a) const
	{
		return !this->operator<=(a);
	}

	bool operator<(const Address& a) const
	{
		if (this->_state < a._state)
			return true;
		else if (this->_state == a._state)
		{
			if (this->_city < a._city)
				return true;
			else if (this->_city == a._city)
			{
				if (this->_name < a._name)
					return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}

	bool operator>=(const Address& a) const
	{
		if (this->operator==(a) || this->operator<(a))
			return true;
		else return false;
	}

	bool operator<=(const Address& a) const
	{
		if (this->operator==(a) || this->operator<(a))
			return true;
		else return false;
	}

	bool operator==(const Address& a) const
	{
		if (this->_name != a._name)
			return false;
		else if (this->_city != a._city)
			return false;
		else if (this->_state != a._state)
			return false;
		else return true;
	}

	bool operator!=(const Address& a) const
	{
		return !this->operator==(a);
	}

	std::string get_name()
	{
		return _name;
	}

	std::string get_email()
	{
		return _email;
	}

	std::string get_street()
	{
		return _street;
	}

	std::string get_city()
	{
		return _city;
	}

	std::string get_state()
	{
		return _state;
	}

	int get_postalCode()
	{
		return _postalCode;
	}

	void set_name(std::string name)
	{
		_name = name;
	}

	void set_email(std::string email)
	{
		_email = email;
	}

	void set_street(std::string street)
	{
		_street = street;
	}

	void set_city(std::string city)
	{
		_city = city;
	}

	void set_state(std::string state)
	{
		_state = state;
	}

	void set_postalCode(int pc)
	{
		if (pc > 10000 && 99999)
		_postalCode = pc;
	}



};



#endif