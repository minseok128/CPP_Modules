/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:46:11 by michang           #+#    #+#             */
/*   Updated: 2024/03/06 21:38:04 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static int	isStrWhitespaceOnly(const std::string &str)
{
	if (str.empty())
		return (1);
	for (int i = 0; i < str.length(); i++)
		if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			return (0);
	return (1);
}

static int	isPrintable(const std::string &str)
{
	for (int i = 0; i < str.length(); i++)
		if (str[i] < 32 || str[i] > 126)
			return (0);
	return (1);
}

void	search(PhoneBook& pb)
{
	std::string	input;
	long long	idx;
	char		*end;

	pb.printAllContact();

	std::cout << "index : ";
	std::getline(std::cin, input);
	idx = std::strtoll(input.c_str(), &end, 10);
	if (!(end != input.c_str() && *end == '\0'))
		throw (std::logic_error("Not a integer"));
	try
	{
		pb.searchContact(idx).printLong();
	}
	catch (std::out_of_range &e)
	{
		throw (std::logic_error("Index out of range"));
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
	std::cout << "\nAdd new contact on #" << pb.getIdx() << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	if (isStrWhitespaceOnly(firstName) || !isPrintable(firstName))
		throw (std::logic_error("Invalid First name"));
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	if (isStrWhitespaceOnly(lastName) || !isPrintable(lastName))
		throw (std::logic_error("Invalid Last name"));
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if (isStrWhitespaceOnly(nickname) || !isPrintable(nickname))
		throw (std::logic_error("Invalid Nickname"));
	std::cout << "Phone number: ";
	std::getline(std::cin, phoneNumber);
	if (isStrWhitespaceOnly(phoneNumber) || !isPrintable(phoneNumber))
		throw (std::logic_error("Invalid Phone number"));
	std::cout << "secret: ";
	std::getline(std::cin, secret);
	if (isStrWhitespaceOnly(secret) || !isPrintable(secret))
		throw (std::logic_error("Invalid secret"));

	pb.addContact(firstName, lastName, nickname, phoneNumber, secret);
	std::cout << "Done!" << std::endl;
}

int	main()
{
	std::string	input;
	PhoneBook	pb;

	while (42)
	{
		std::cout << "\nSelect command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, input))
			break; ;
		try
		{
			if (input == "ADD")
				add(pb);
			else if (input == "SEARCH")
				search(pb);
			else if (input == "EXIT")
				break;
			else
				std::cout << "Invalid command" << std::endl;
		}
		catch (std::logic_error &e)
		{
			std::cout << "\n[Error]: " << e.what() << std::endl;
		}
	}
	return (0);
}
