#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure")
{
}

Cure::Cure(const Cure& obj)
	: AMateria(obj._type)
{
}

Cure::~Cure()
{
}

Cure&	Cure::operator=(const Cure& obj)
{
	return (*this);
}

AMateria*	Cure::clone() const
{
	AMateria*	newCure = new Cure(*this);

	return (newCure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName()
		<< "'s wounds *" << std::endl;
}
