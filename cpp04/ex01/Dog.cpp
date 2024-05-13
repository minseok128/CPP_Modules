#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << _type << " constructor" << std::endl;
}

Dog::Dog(const Dog& obj)
{
	*this = obj;
	std::cout << _type << " copy constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << _type << " destructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& obj)
{
	if (this != &obj)
	{
		_type = obj._type;
	}
	std::cout << _type << " copy assignment operator" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}
