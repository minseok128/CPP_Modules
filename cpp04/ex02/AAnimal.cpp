#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal constructor" << std::endl;
}

AAnimal::AAnimal(const std::string& type)
	: _type(type)
{
	std::cout << "AAnimal parameterized constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj)
	: _type(obj._type)
{
	std::cout << "AAnimal copy constructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& obj)
{
	if (this != &obj)
		_type = obj._type;
	std::cout << "AAnimal copy assignment operator" << std::endl;
	return (*this);
}

const std::string&	AAnimal::getType() const
{
	return (_type);
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal sound" << std::endl;
}