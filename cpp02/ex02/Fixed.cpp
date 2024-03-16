/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:45:43 by michang           #+#    #+#             */
/*   Updated: 2024/03/16 17:45:51 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_FBITS = 8;

Fixed::Fixed()
	: _rawBits(0)
{
}

Fixed::Fixed(const Fixed& rhs)
{
	*this = rhs;
}

Fixed::Fixed(const int src)
	: _rawBits(src << _FBITS)
{
}

Fixed::Fixed(const float src)
	: _rawBits(roundf(src * (1 << _FBITS)))
{
}

Fixed::~Fixed()
{
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
		_rawBits = rhs._rawBits;
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& r) const
{
	Fixed	tmp;

	tmp._rawBits = _rawBits + r._rawBits;
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& r) const
{
	Fixed	tmp;

	tmp._rawBits = _rawBits - r._rawBits;
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& r) const
{
	Fixed	tmp;

	tmp._rawBits = (_rawBits * r._rawBits) >> _FBITS;
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& r) const
{
	Fixed	tmp;

	tmp._rawBits = (_rawBits / r._rawBits) >> _FBITS;
	return (tmp);
}

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> 8);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / static_cast<float>((1 << _FBITS)));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
