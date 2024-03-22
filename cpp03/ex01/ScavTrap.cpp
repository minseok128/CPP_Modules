/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:26:27 by michang           #+#    #+#             */
/*   Updated: 2024/03/22 17:15:19 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout <<  "ScavTrap parameterized constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	std::cout << "ScavTrap copy constructor called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout <<  "ScavTrap destructor called!" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "ScavTrap copy assignment operator constructor called!" << std::endl;
}
