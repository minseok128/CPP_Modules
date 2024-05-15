#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
}

Ice::Ice(const Ice& obj)
	: AMateria(obj._type)
{
}

Ice::~Ice()
{
}

Ice&	Ice::operator=(const Ice& obj)
{
	(void)obj;
	return (*this);
}

AMateria*	Ice::clone() const
{
	AMateria*	newIce = new Ice(*this);

	return (newIce);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}
