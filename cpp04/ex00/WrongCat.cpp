#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << _type << " constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
	*this = obj;
	std::cout << _type << " copy constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << _type <<  " destructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
	{
		_type = obj._type;
	}
	std::cout << _type << " copy assignment operator" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow Meow" << std::endl;
}
