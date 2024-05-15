#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const AMateria& obj)
	: _type(obj._type)
{
}

AMateria::AMateria(const std::string& type)
	: _type(type)
{
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator=(const AMateria& obj)
{
	if (this != &obj)
	{
		_type = obj._type;
	}
	return (*this);
}

const std::string&	AMateria::getType() const
{
	return (_type);
}
