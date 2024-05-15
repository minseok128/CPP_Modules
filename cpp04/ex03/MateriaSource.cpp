#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj._inventory[i] != 0)
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

MateriaSource::~MateriaSource()
{
	for	(int i = 0; i < 4; i++)
		delete _inventory[i];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (obj._inventory[i] != 0)
				_inventory[i] = obj._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
	}
}
void	MateriaSource::learnMateria(AMateria* m)
{
	int	i;

	if (m == 0)
	{
		std::cout << "Invalid materia" << std::endl;
		return ;
	}
	for (i = 0; i < 4; i++)
	{
		if (_inventory[i] == 0)
		{
			_inventory[i] = m->clone();
			break;
		}
	}
	if (i == 4)
		std::cout << "Inventory is full" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != 0 && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	return (0);
}
