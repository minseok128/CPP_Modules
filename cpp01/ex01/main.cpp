/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:09:14 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 14:15:03 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

// #include <cstdio>
// void	a()
// {
// 	system("leaks --list zombieHorde");
// }

int	main()
{
	int		n = 5;
	Zombie	*horde;

	// atexit(a);
	horde = zombieHorde(n, "zombie");

	for (int i = 0; i < n; ++i)
		horde[i].announce();

	delete[] horde;
	return (0);
}