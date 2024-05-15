#include "Floor.hpp"

Floor::Floor()
	: _idx(0)
{
	for (int i = 0; i < 10; i++)
		_inventory[i] = 0;
}

Floor::Floor(const Floor& obj)
	: _idx(obj._idx)
{
	for (int i = 0; i < 10; i++)
	{
		if (obj._inventory[i] != 0)
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Floor::~Floor()
{
	for (int i = 0; i < 10; i++)
		delete _inventory[i];
}

Floor&	Floor::operator=(const Floor& obj)
{
	if (this != &obj)
	{
		_idx = obj._idx;
		for (int i = 0; i < 10; i++)
		{
			delete _inventory[i];
			if (obj._inventory[i] != 0)
				_inventory[i] = obj._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
	}
	return (*this);
}

void	Floor::push(AMateria* m)
{
	_idx = (_idx + 1) % 10;
	if (_inventory[_idx] != 0)
		delete _inventory[_idx];
	_inventory[_idx] = m;
}

void	Floor::clean()
{
	for (int i = 0; i < 10; i++)
	{
		delete _inventory[i];
		_inventory[i] = 0;
	}
}
