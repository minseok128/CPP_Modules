/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:49:09 by michang           #+#    #+#             */
/*   Updated: 2024/03/06 20:35:25 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact() 
	: _firstName(""),
	  _lastName(""),
	  _nickname(""),
	  _phoneNumber(""),
	  _secret("")
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

std::string	Contact::getFirstName()
{
	return (_firstName);
}

void	Contact::setLastName(std::string lastName)
{
	_lastName = lastName;
}

void	Contact::setNickname(std::string nickname)
{
	_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::setSecret(std::string secret)
{
	_secret = secret;
}

std::string	cutStr10(std::string str)
{
	if (str.length() > 10)
		return(str.substr(0, 9).append("."));
	else
		return(str);
}

void	Contact::printShort()
{
	std::cout << std::setw(10) << cutStr10(_firstName) << "|";
	std::cout << std::setw(10) << cutStr10(_lastName) << "|";
	std::cout << std::setw(10) << cutStr10(_nickname) << std::endl;
}
