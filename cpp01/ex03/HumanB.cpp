/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:59:12 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 15:13:56 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: _name(name)
{
	_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (_weapon != NULL)
		std::cout << _name << "attacks with their" << _weapon->getType() << std::endl;
	else
		std::cout << _name << "does not have a weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
