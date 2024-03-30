/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:32:28 by michang           #+#    #+#             */
/*   Updated: 2024/03/30 16:42:17 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_name = "Default";
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::F_HIT_POINTS;
	_energyPoints = ScavTrap::S_ENERGY_POINTS;
	_attackDamage = FragTrap::F_ATTACK_DAMAGE;
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::F_HIT_POINTS;
	_energyPoints = ScavTrap::S_ENERGY_POINTS;
	_attackDamage = FragTrap::F_ATTACK_DAMAGE;
	std::cout << "DiamondTrap parameterized constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
{
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
	*this = obj;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& obj)
{
	std::cout << "DiamondTrap copy assignment operator constructor called!" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		ClapTrap::_name = obj.ClapTrap::_name;
		_hitPoints = obj._hitPoints;
		_energyPoints = obj._energyPoints;
		_attackDamage = obj._attackDamage;
		_isGatekeeperMode = obj._isGatekeeperMode;
	}
	return (*this);
}

void	DiamondTrap::printInfo() const
{
	std::cout << "DiamondTrap " << _name << " has " << _hitPoints
		<< " hit points, " << _energyPoints << " energy points, and "
		<< _attackDamage << " attack damage!" << std::endl;	
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}