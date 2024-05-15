#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << _type << " constructor" << std::endl;
}

Cat::Cat(const Cat& obj)
	: Animal(obj._type)
{
	std::cout << _type << " copy constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << _type <<  " destructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		_type = obj._type;
	}
	std::cout << _type << " copy assignment operator" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
