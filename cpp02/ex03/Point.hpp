/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:28 by michang           #+#    #+#             */
/*   Updated: 2024/03/18 12:58:16 by michang          ###   ########.fr       */
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

private:
	const Fixed	_x;
	const Fixed	_y;
};

#endif
