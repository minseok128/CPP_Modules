/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:46:32 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 13:51:36 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

// #include <cstdio>
// void	a()
// {
// 	system("leaks --list BraiiiiiiinnnzzzZ");
// }

int	main()
{
	Zombie	*zombie1;

	// atexit(a);
	zombie1 = newZombie("zombie1");
	zombie1->announce();
	std::cout << std::endl;

	randomChump("zombie2");
	std::cout << std::endl;
	
	delete zombie1;
	std::cout << std::endl;
	return (0);
}