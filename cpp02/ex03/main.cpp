/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:20:18 by michang           #+#    #+#             */
/*   Updated: 2024/03/18 14:06:11 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(0.0f, 2.0f);
	Point c(1.0f, 0.0f);

	Point pointInside(0.2f, 0.2f);
	Point pointOutside(1.0f, 1.0f);
	Point pointOnEdge(0.5f, 1.0f);

	std::cout << "Point inside: " << (bsp(a, b, c, pointInside) ? "Yes" : "No") << std::endl;
	std::cout << "Point outside: " << (bsp(a, b, c, pointOutside) ? "Yes" : "No") << std::endl;
	std::cout << "Point on edge: " << (bsp(a, b, c, pointOnEdge) ? "Yes" : "No") << std::endl;
	return (0);
}
