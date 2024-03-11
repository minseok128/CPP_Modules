/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:23:00 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 17:49:31 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int	printError(std::string name)
{
	std::cout << "Useage " << name << " [DEBUG/INFO/WARNING/ERROR]" << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
		return (printError(argv[0]));
	try
	{
		harl.complain(argv[1]);
	}
	catch (int e)
	{
		return (printError(argv[0]));
	}
}