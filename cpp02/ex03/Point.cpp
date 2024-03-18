/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:35 by michang           #+#    #+#             */
/*   Updated: 2024/03/18 12:58:52 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	: _x(), _y()
{
}

Point::Point(const Point& obj)
{
	
}

Point::Point(float x, float y)
	: _x(x), _y(y)
{
}


Point::~Point()
{
}

Point&	Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
		this->~Point();
		new(this) Point(obj._x.toFloat(), obj._y.toFloat());
	}
	return (*this);
}
