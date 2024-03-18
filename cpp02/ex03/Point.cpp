/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:35 by michang           #+#    #+#             */
/*   Updated: 2024/03/18 12:21:39 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const Point& rhs);
	Point(float x, float y);
	~Point();
	Point&	operator=(const Point& rhs);
private:
	const Fixed	_x;
	const Fixed	_y;
};

#endif
