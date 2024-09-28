/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:13:43 by michang           #+#    #+#             */
/*   Updated: 2024/09/28 21:18:44 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main() {
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	// return 0;

	Span sp = Span(100000);
	sp.addNumbers(1, 100, 50000);
	sp.addNumbers(1, 100, 49999);
	sp.addNumber(50);

	try {
		sp.addNumber(0);
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		sp.addNumbers(1, 100, 1000);
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}