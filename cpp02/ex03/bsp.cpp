/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:02:56 by michang           #+#    #+#             */
/*   Updated: 2024/03/18 14:04:12 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	const Point*	arr[4];

	arr[0] = &a;
	if (Point::cross_product(a, b, a, c) >= Fixed(0))
	{
		arr[1] = &b;
		arr[2] = &c;
	}
	else
	{
		arr[1] = &c;
		arr[2] = &b;
	}
	arr[3] = &a;
	
	for (int i = 0; i < 3; i++)
		if (Point::cross_product(*arr[i], *arr[i + 1], *arr[i], point) < Fixed(0))
			return (false);
	return (true);
}
