#include "Animal.hpp"

Animal::Animal()
{
}

Animal::Animal(const std::string& type) : _type(type)
{
}

Animal::Animal(const Animal& obj)
{
}

Animal::~Animal()
{
}

Animal&	Animal::operator=(const Animal& obj)
{
}

const std::string&	Animal::getType() const
{
	return (_type);
}