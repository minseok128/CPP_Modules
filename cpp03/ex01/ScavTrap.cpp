/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:26:27 by michang           #+#    #+#             */
/*   Updated: 2024/03/30 13:08:24 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap(), _isGatekeeperMode(0)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name), _isGatekeeperMode(0)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout <<  "ScavTrap parameterized constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	std::cout << "ScavTrap copy constructor called!" << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout <<  "ScavTrap destructor called!" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "ScavTrap copy assignment operator constructor called!" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_energyPoints = obj._energyPoints;
		_attackDamage = obj._attackDamage;
	}
	return (*this);
}

void	ScavTrap::guardGate()
{
	if (_isGatekeeperMode == 1)
	{
		std::cout << "ScavTrap " << _name
			<< " is already in Gatekeeper mode" << std::endl;	
		return ;
	}
	if (_energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name
			<< " has entered Gatekeeper mode" << std::endl;	
		_energyPoints--;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " tried to enter Gatekeeper mode, "
			<< "but there's not enough energy points!" << std::endl;
	}
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " tried to attack "
			<< target << ", but there's not enough energy points!" << std::endl;
	}
}
