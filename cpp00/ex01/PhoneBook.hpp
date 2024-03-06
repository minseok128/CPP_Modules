/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:47:08 by michang           #+#    #+#             */
/*   Updated: 2024/03/06 15:11:39 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include "Contact.hpp"
# define MAXIDX 8

class PhoneBook
{
public :
	PhoneBook();
	~PhoneBook();
	int			getIdx();
	Contact&	searchContact(long long idx);
	void		addContact(std::string firstName, std::string lastName, \
		std::string nickname, std::string phoneNumber, std::string secret);

private :
	Contact		_list[MAXIDX];
	int			_idx;
};

#endif