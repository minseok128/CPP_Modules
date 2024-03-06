/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:47:08 by michang           #+#    #+#             */
/*   Updated: 2024/03/06 21:25:54 by michang          ###   ########.fr       */
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
	int			getIdx() const;
	Contact&	searchContact(long long idx);
	void		addContact(std::string firstName, std::string lastName, \
					std::string nickname, std::string phoneNumber, std::string secret);
	void		printAllContact();

private :
	Contact		_list[MAXIDX];
	int			_idx;
};

#endif