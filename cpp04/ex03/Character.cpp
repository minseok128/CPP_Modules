#include "Character.hpp"

Character::Character()
	: _name("default"), _floor(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character& obj)
	: _name(obj._name), _floor(obj._floor)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj._inventory[i] != 0)
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character::Character(const std::string& name)
	: _name(name), _floor(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

Character&	Character::operator=(const Character& obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		_floor = obj._floor;
		for (int i = 0; i < 4; i++)
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

const std::string&	Character::getName() const
{
	return (_name);
}

void	Character::setFloor(Floor* floor)
{
	_floor = floor;
}

void	Character::equip(AMateria* m)
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
			_inventory[i] = m;
			break;
		}
	}
	if (i == 4)
		std::cout << "Inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid inventory index" << std::endl;
		return;
	}
	if (_inventory[idx] == 0)
	{
		std::cout << "Inventory[" << idx << "] is aleady empty" << std::endl;
		return ;
	}
	if (_floor == 0)
		std::cout << "Floor is not set" << std::endl;
	_floor->push(_inventory[idx]);
	_inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid inventory index" << std::endl;
		return;
	}
	if (_inventory[idx] == 0)
	{
		std::cout << "Inventory[" << idx << "] is aleady empty" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}
