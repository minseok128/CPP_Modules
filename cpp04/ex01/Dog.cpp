#include "Dog.hpp"

Dog::Dog()
	: Animal("Dog")
{
	std::cout << _type << " constructor" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& obj)
	: Animal(obj)
{
	std::cout << _type << " copy constructor" << std::endl;
	_brain = new Brain(*(obj._brain));
}

Dog::~Dog()
{
	delete _brain;
	std::cout << _type << " destructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& obj)
{
	std::cout << _type << " copy assignment operator" << std::endl;
	if (this != &obj)
	{
		_type = obj._type;
		*_brain = *(obj._brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}
