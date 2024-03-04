/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:49:09 by michang           #+#    #+#             */
/*   Updated: 2024/03/04 15:09:39 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void	Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}
