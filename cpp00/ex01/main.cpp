/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:46:11 by michang           #+#    #+#             */
/*   Updated: 2024/03/06 15:24:56 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static int	isWhitespaceOnly(const std::string &str)
{
	if (str.empty())
		return (1);
	for (int i = 0; i < str.length(); i++)
		if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			return (0);
	return (1);
}

void	search(PhoneBook& pb)
{
	std::string	input;
	long long	idx;
	char		*end;

	std::cout << "index : ";
	std::getline(std::cin, input);
	idx = std::strtoll(input.c_str(), &end, 10);
	if (!(end != input.c_str() && *end == '\0'))
		throw std::logic_error("not a integer");
	try
	{
		pb.searchContact(idx);
	}
	catch (std::out_of_range &e)
	{
		throw std::logic_error("index out of range");
	}
}

void	add(PhoneBook& pb)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;
	
	// input
	std::cout << "Add new contact on #" << pb.getIdx() << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	if (isWhitespaceOnly(firstName))
		throw std::logic_error("First name is empty");
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	if (isWhitespaceOnly(lastName))
		throw std::logic_error("Last name is empty");
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if (isWhitespaceOnly(nickname))
		throw std::logic_error("Nickname is empty");
	std::cout << "Phone number: ";
	std::getline(std::cin, phoneNumber);
	if (isWhitespaceOnly(phoneNumber))
		throw std::logic_error("Phone number is empty");
	std::cout << "secret: ";
	std::getline(std::cin, secret);
	if (isWhitespaceOnly(secret))
		throw std::logic_error("secret is empty");

	pb.addContact(firstName, lastName, nickname, phoneNumber, secret);
	std::cout << "Done!" << std::endl;
}

int	main()
{
	std::string	input;
	PhoneBook	pb;

	while (42)
	{
		std::getline(std::cin, input);
		try
		{
			if (input == "ADD")
				add(pb);
			else if (input == "SEARCH")
				search(pb);
			else if (input == "EXIT")
				break;
			else
				std::cout << "Invalid command : " << input << std::endl;
		}
		catch (std::logic_error &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	return (0);
}
