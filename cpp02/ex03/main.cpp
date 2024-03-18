/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:20:18 by michang           #+#    #+#             */
/*   Updated: 2024/03/18 12:01:09 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << std::endl;


	std::cout << "+ test" << std::endl;
	std::cout << Fixed(0.75f) + Fixed(0.5f) << std::endl;
	std::cout << Fixed(2000.75f) + Fixed(0.05f) << std::endl;
	std::cout << std::endl;

	std::cout << "- test" << std::endl;
	std::cout << Fixed(1.125f) - Fixed(0.5f) << std::endl;
	std::cout << Fixed(5.125f) - Fixed(10.5f) << std::endl;
	std::cout << std::endl;

	std::cout << "* test" << std::endl;
	std::cout << Fixed(1.0f) * Fixed(0.5f) << std::endl;
	std::cout << Fixed(1.125f) * Fixed(10.5f) << std::endl;
	std::cout << std::endl;

	std::cout << "/ test" << std::endl;
	std::cout << Fixed(255.0f) / Fixed(4) << std::endl;
	std::cout << Fixed(1.125f) / Fixed(0.25f) << std::endl;
	std::cout << std::endl;
	return (0);
}
