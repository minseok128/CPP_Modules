/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:38:33 by michang           #+#    #+#             */
/*   Updated: 2024/09/28 21:44:24 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
	std::vector<int> v(5, 0);

	for (int i = 0; i < 5; i++)
		v[i] = i;

	std::cout << easyfind(v, -2) << std::endl;
	std::cout << easyfind(v, 0) << std::endl;
	std::cout << easyfind(v, 3) << std::endl;
	std::cout << easyfind(v, 6) << std::endl;
	std::cout << std::endl;

	std::list<int> l;
	for (int i = 0; i < 5; i++)
		l.push_back(i);

	std::cout << easyfind(l, -2) << std::endl;
	std::cout << easyfind(l, 0) << std::endl;
	std::cout << easyfind(l, 3) << std::endl;
	std::cout << easyfind(l, 6) << std::endl;
	std::cout << std::endl;

	std::deque<int> d;
	for (int i = 0; i < 5; i++)
		d.push_back(i);

	std::cout << easyfind(d, -2) << std::endl;
	std::cout << easyfind(d, 0) << std::endl;
	std::cout << easyfind(d, 3) << std::endl;
	std::cout << easyfind(d, 6) << std::endl;
	std::cout << std::endl;
}