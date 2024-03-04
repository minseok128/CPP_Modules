/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:46:11 by michang           #+#    #+#             */
/*   Updated: 2024/03/04 15:06:46 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	search(PhoneBook& pb)
{
	
}

void	add(PhoneBook& pb)
{
	
}

int	main()
{
	std::string	input;
	PhoneBook	pb;

	while (42)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
			add(pb);
		else if (input == "SEARCH")
			search(pb);
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid command : " << input << std::endl;
	}
	return (0);
}
