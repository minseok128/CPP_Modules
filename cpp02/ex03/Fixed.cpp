/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:45:43 by michang           #+#    #+#             */
/*   Updated: 2024/03/18 14:03:50 by michang          ###   ########.fr       */
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
	return (toFloat() * r.toFloat());
}

Fixed	Fixed::operator/(const Fixed& r) const
{
	return (toFloat() / r.toFloat());
}

bool	Fixed::operator==(const Fixed& r) const
{
	return (_rawBits == r._rawBits);
}

bool	Fixed::operator!=(const Fixed& r) const
{
	return (_rawBits != r._rawBits);
}

bool	Fixed::operator>(const Fixed& r) const
{
	return (_rawBits > r._rawBits);
}

bool	Fixed::operator<(const Fixed& r) const
{
	return (_rawBits < r._rawBits);
}

bool	Fixed::operator>=(const Fixed& r) const
{
	return (_rawBits >= r._rawBits);
}

bool	Fixed::operator<=(const Fixed& r) const
{
	return (_rawBits <= r._rawBits);
}

const Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	_rawBits++;
	return (tmp);
}

Fixed&	Fixed::operator++()
{
	_rawBits++;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	_rawBits--;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	_rawBits--;
	return (*this);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (b > a)
		return (b);
	return (a);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (b > a)
		return (b);
	return (a);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (b);
	return (a);
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
