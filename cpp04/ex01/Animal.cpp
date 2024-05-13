#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const std::string& type)
	: _type(type)
{
	std::cout << "Animal parameterized constructor" << std::endl;
}

Animal::Animal(const Animal& obj)
	: _type(obj._type)
{
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

Animal&	Animal::operator=(const Animal& obj)
{
	if (this != &obj)
		_type = obj._type;
	std::cout << "Animal copy assignment operator" << std::endl;
	return (*this);
}

const std::string&	Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}