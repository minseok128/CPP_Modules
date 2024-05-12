#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
	std::cout << "WrongAnimal parameterized constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	*this = obj;
	std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this != &obj)
	{
		_type = obj._type;
	}
	std::cout << "WrongAnimal copy assignment operator" << std::endl;
	return (*this);
}

const std::string&	WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}