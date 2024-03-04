/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:47:08 by michang           #+#    #+#             */
/*   Updated: 2024/03/04 13:57:01 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include "Contact.hpp"
# define MAXIDX 10

class PhoneBook
{
public :
	PhoneBook();
	~PhoneBook();
	void	addContact();
	Contact	&searchContact(int idx);

private :
	Contact		_list[MAXIDX];
	int			_idx;
};

#endif