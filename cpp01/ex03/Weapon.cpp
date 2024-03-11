/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:45:45 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 14:49:21 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
	: _type("")
{
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
