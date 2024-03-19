/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:31:21 by michang           #+#    #+#             */
/*   Updated: 2024/03/19 12:15:10 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
}

ClapTrap::~ClapTrap()
{
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
}
