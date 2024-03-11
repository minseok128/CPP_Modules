/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:21:27 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 16:01:29 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "WordChanger.hpp"

void	run(std::ifstream &ifs, std::string s1, std::string s2)
{
	WordChanger			wc;
	std::stringstream	buffer;
	std::string			totalStr;

	buffer << ifs.rdbuf();
	totalStr = buffer.str();
	ifs.close();
	wc.setTotalStr(totalStr);
	totalStr = wc.changeWord(s1, s2);
	std::cout << totalStr;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
		
	std::ifstream ifs(argv[1]);
	if (!ifs.is_open())
		std::cout << "Can't open " << argv[1] << std::endl;
	else
		run(ifs, argv[2], argv[3]);		
}