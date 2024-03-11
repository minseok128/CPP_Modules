/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:23:00 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 20:09:24 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int	printError()
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
		return (printError());
	try
	{
		harl.complain(argv[1]);
	}
	catch (int e)
	{
		return (printError());
	}
}