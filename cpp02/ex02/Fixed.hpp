/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:42:49 by michang           #+#    #+#             */
/*   Updated: 2024/03/16 15:59:31 by michang          ###   ########.fr       */
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
	Fixed&	operator=(const Fixed& rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

private:
	static const int	_FBITS;
	int					_rawBits;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif