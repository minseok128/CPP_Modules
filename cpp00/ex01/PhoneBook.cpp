/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:47:13 by michang           #+#    #+#             */
/*   Updated: 2024/03/04 13:53:40 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_idx = 0;
}

PhoneBook::~PhoneBook()
{
}

static int	isWhitespaceOnly(const std::string &str)
{
	if (str.empty())
		return (1);
	for (int i = 0; i < str.length(); i++)
		if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			return (0);
	return (1);
}

void	PhoneBook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;

	// input
	std::cout << "Add new contact on #" << this->_idx << std::endl;
	std::cout << "First name: ";
	std::cin >> firstName;
	if (isWhitespaceOnly(firstName))
		throw std::logic_error("First name is empty");
	std::cout << "Last name: ";
	std::cin >> lastName;
	if (isWhitespaceOnly(lastName))
		throw std::logic_error("Last name is empty");
	std::cout << "Nickname: ";
	std::cin >> nickname;
	if (isWhitespaceOnly(nickname))
		throw std::logic_error("Nickname is empty");
	std::cout << "Phone number: ";
	std::cin >> phoneNumber;
	if (isWhitespaceOnly(phoneNumber))
		throw std::logic_error("Phone number is empty");
	std::cout << "secret: ";
	std::cin >> secret;
	if (isWhitespaceOnly(secret))
		throw std::logic_error("secret is empty");
	
	// save
	this->_list[_idx].setFirstName(firstName);
	this->_list[_idx].setLastName(lastName);
	this->_list[_idx].setNickname(nickname);
	this->_list[_idx].setPhoneNumber(phoneNumber);
	this->_list[_idx].setSecret(secret);
	std::cout << "Done!" << std::endl;
	_idx = (_idx + 1) % MAXIDX;
}
