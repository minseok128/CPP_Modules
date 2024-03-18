/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:28 by michang           #+#    #+#             */
/*   Updated: 2024/03/18 13:55:10 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const Point& obj);
	Point(float x, float y);
	~Point();
	Point&	operator=(const Point& obj);
	Fixed			getX() const;
	Fixed			getY() const;
	static Fixed	cross_product(const Point& a, const Point& b,\
		const Point& c, const Point& d);

private:
	const Fixed	_x;
	const Fixed	_y;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif
