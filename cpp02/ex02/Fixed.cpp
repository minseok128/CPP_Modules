/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:45:43 by michang           #+#    #+#             */
/*   Updated: 2024/03/16 15:56:38 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_FBITS = 8;

Fixed::Fixed()
	: _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::Fixed(const int src)
	: _rawBits(src << _FBITS)
{
	std::cout << "Int constructor called" << std::endl;
}

// 0 10000100 01010011010111000010100
// 0 10001100 01010011010111000010100
// 0 10001100 01010011011000000000000
// 101010 10011011

Fixed::Fixed(const float src)
	: _rawBits(roundf(src * (1 << _FBITS)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_rawBits = rhs._rawBits;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> 8);
}

float	Fixed::toFloat(void) const
{
	return (_rawBits / ((1 << _FBITS) * 1.0));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
