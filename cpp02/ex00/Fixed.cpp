/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:45:43 by michang           #+#    #+#             */
/*   Updated: 2024/03/12 16:08:39 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

const int Fixed::_FBITS = 8;

Fixed::Fixed()
	: _num(0)
{
	std::cout << "Defalut Constructor" << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = rhs;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy Assignment Operator" << std::endl;
	if (this != &rhs)
	{
		_num = rhs._num;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Default Destructor" << std::endl;
}
