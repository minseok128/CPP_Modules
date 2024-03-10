/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:46:11 by michang           #+#    #+#             */
/*   Updated: 2024/03/10 18:43:43 by michang          ###   ########.fr       */
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

static int	isStrPrintable(const std::string &str)
{
	for (int i = 0; i < str.length(); i++)
		if (str[i] < 32 || str[i] > 126)
			return (0);
	return (1);
}

void	search(PhoneBook& pb)
{
	std::string	input;
	int			idx;
	char		*end;

	pb.printAllContact();

	std::cout << "index : ";
	std::getline(std::cin, input);
	idx = std::strtol(input.c_str(), &end, 10);
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
	if (isStrWhitespaceOnly(firstName) || !isStrPrintable(firstName))
		throw (std::logic_error("Invalid First name"));
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	if (isStrWhitespaceOnly(lastName) || !isStrPrintable(lastName))
		throw (std::logic_error("Invalid Last name"));
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if (isStrWhitespaceOnly(nickname) || !isStrPrintable(nickname))
		throw (std::logic_error("Invalid Nickname"));
	std::cout << "Phone number: ";
	std::getline(std::cin, phoneNumber);
	if (isStrWhitespaceOnly(phoneNumber) || !isStrPrintable(phoneNumber))
		throw (std::logic_error("Invalid Phone number"));
	std::cout << "secret: ";
	std::getline(std::cin, secret);
	if (isStrWhitespaceOnly(secret) || !isStrPrintable(secret))
		throw (std::logic_error("Invalid secret"));

	pb.addContact(firstName, lastName, nickname, phoneNumber, secret);
	std::cout << "Done!" << std::endl;
}

int	main(int argc, char **argv)
{
	std::string	input;
	PhoneBook	pb;

	if (argc > 1)
	{
		std::cout << "Usage: " << argv[0] << std::endl;
		return (1);
	}
	std::cout << "Welcome to the phonebook!" << std::endl;
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
