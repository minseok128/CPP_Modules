/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:31:21 by michang           #+#    #+#             */
/*   Updated: 2024/03/19 15:33:08 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout <<  "ClapTrap parameterized constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "ClapTrap copy constructor called!" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout <<  "ClapTrap destructor called!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "ClapTrap copy assignment operator constructor called!" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_energyPoints = obj._energyPoints;
		_attackDamage = obj._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << "attacks " << target
			<< ", causing " << _attackDamage << "points of damage!" << std::endl;
		_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " tried to attack "
			<< target << ", but there's not enough energy points!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " takes "
			<< amount << " points of damage!" << std::endl;
		_hitPoints = _hitPoints - amount > 0 ? _hitPoints : 0;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " cannot take damage because "
			<< "it's already out of hit points!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " repairs itself, "
			<< "recovering " << amount << " hit points!" << std::endl;
		_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " tried to repair itself, "
			<< "but there's not enough energy points!" << std::endl;
	}
}
