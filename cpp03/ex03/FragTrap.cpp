/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:26:27 by michang           #+#    #+#             */
/*   Updated: 2024/03/30 16:32:55 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "FragTrap.hpp"

const unsigned int FragTrap::F_HIT_POINTS = 100;
const unsigned int FragTrap::F_ATTACK_DAMAGE = 30;

FragTrap::FragTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout <<  "FragTrap parameterized constructor called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout <<  "FragTrap destructor called!" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& obj)
{
	std::cout << "FragTrap copy assignment operator constructor called!" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_energyPoints = obj._energyPoints;
		_attackDamage = obj._attackDamage;
	}
	return (*this);
}

void	FragTrap::highFivesGuys() const
{
	if (_hitPoints > 0)
		std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " can't move." << std::endl;
}

void	FragTrap::printInfo() const
{
	std::cout << "FragTrap " << _name << " has " << _hitPoints
		<< " hit points, " << _energyPoints << " energy points, and "
		<< _attackDamage << " attack damage!" << std::endl;	
}
