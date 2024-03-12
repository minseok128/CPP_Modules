/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:42:49 by michang           #+#    #+#             */
/*   Updated: 2024/03/12 16:56:21 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& rhs);
	Fixed&	operator=(const Fixed& rhs);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	static const int	_FBITS;
	int					_rawBits;

};

#endif