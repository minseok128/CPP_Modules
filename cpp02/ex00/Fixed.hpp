/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:42:49 by michang           #+#    #+#             */
/*   Updated: 2024/03/12 16:00:02 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed
{
public:
	Fixed(); // 기본 생성자
	Fixed(const Fixed& rhs); // 복사 생성자
	Fixed&	operator=(const Fixed& rhs); // 복사 대입 연산자
	~Fixed(); // 기본 소멸자

private:
	static const int	_FBITS;
	int					_num;

};

#endif