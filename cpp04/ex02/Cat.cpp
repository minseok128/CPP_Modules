#include "Cat.hpp"

Cat::Cat()
	: AAnimal("Cat")
{
	std::cout << _type << " constructor" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& obj)
	: AAnimal(obj)
{
	std::cout << _type << " copy constructor" << std::endl;
	_brain = new Brain(*(obj._brain));
}

Cat::~Cat()
{
	delete _brain;
	std::cout << _type << " destructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& obj)
{
	std::cout << _type << " copy assignment operator" << std::endl;
	if (this != &obj)
	{
		_type = obj._type;
		*_brain = *(obj._brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
