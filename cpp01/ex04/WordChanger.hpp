/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordChanger.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:21:45 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 16:00:15 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDCHANGER_HPP
# define WORDCHANGER_HPP
# include <iostream>
# include <string>

class WordChanger
{
public:
	WordChanger();
	WordChanger(std::string totalStr);
	~WordChanger();
	void		setTotalStr(std::string str);
	std::string	changeWord(const std::string &s1, const std::string &s2);

private:
	std::string	_totalStr;
};

#endif