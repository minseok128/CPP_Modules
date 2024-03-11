/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:10:21 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 17:50:18 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
	_arr[0] = &Harl::debug;
	_arr[1] = &Harl::info;
	_arr[2] = &Harl::warning;
	_arr[3] = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
		<< "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! "
		<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas "
		<< "you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! "
		<< "I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			level_idx = -1;
	
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			level_idx = i;
	switch (level_idx)
	{
		case (-1):
			throw (1);
		case (0):
			(this->*(_arr[0]))();
		case (1):
			(this->*(_arr[1]))();
		case (2):
			(this->*(_arr[2]))();
		case (3):
			(this->*(_arr[3]))();
	}
}
