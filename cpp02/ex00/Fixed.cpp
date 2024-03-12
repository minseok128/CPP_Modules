/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:45:43 by michang           #+#    #+#             */
/*   Updated: 2024/03/12 15:57:52 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_FBITS = 8;

Fixed::Fixed()
	: _num(0)
{
}

Fixed::Fixed(const Fixed& src)
{
	
}

Fixed::~Fixed()
{
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	if (this != &src)
	{
		_num = src._num;
	}
	return (*this);
}
