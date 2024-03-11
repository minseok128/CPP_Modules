/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordChanger.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:21:45 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 15:34:56 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDCHANGER_HPP
# define WORDCHANGER_HPP
# include <iostream>
# include <string>

class WordChanger
{
public:
	WordChanger(std::string totalStr);
	~WordChanger();
	std::string	changeWord(std::string s1, std::string s2);

private:
	std::string	_totalStr;
};

#endif