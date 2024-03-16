/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:42:49 by michang           #+#    #+#             */
/*   Updated: 2024/03/16 16:35:26 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& rhs);
	Fixed(const int src);
	Fixed(const float src);
	~Fixed();

	Fixed&			operator=(const Fixed& rhs);
	Fixed			operator+(const Fixed& r);
	Fixed			operator-(const Fixed& r);
	Fixed			operator*(const Fixed& r);
	Fixed			operator/(const Fixed& r);

	bool			operator==(const Fixed& r);
	bool			operator!=(const Fixed& r);
	bool			operator>(const Fixed& r);
	bool			operator<(const Fixed& r);
	bool			operator<=(const Fixed& r);
	bool			operator>=(const Fixed& r);

	Fixed			operator++(int);
	Fixed&			operator++();
	Fixed			operator--(int);
	Fixed&			operator--();

	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	int				toInt(void) const;
	float			toFloat(void) const;

	static Fixed&	max(Fixed& a, Fixed& b);
	static Fixed&	max(const Fixed& a, const Fixed& b);
	static Fixed&	min(Fixed& a, Fixed& b);
	static Fixed&	min(const Fixed& a, const Fixed& b);

private:
	static const int	_FBITS;
	int					_rawBits;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif