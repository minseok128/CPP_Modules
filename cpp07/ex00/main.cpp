/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:17:35 by michang           #+#    #+#             */
/*   Updated: 2024/07/12 18:36:34 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void) {
	{
		std::cout << "subject test\n";
		int a = 2;
		int b = 3;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
		std::cout << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}
	return 0;
}