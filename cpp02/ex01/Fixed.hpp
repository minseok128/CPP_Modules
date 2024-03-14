/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:42:49 by michang           #+#    #+#             */
/*   Updated: 2024/03/14 14:27:55 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed
{
public:
	Fixed();
	Fixed(const int src);
	Fixed(const float src);
	Fixed(const Fixed& rhs);
	Fixed&	operator=(const Fixed& rhs); 
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	static const int	_FBITS;
	int					_rawBits;

};

#endif