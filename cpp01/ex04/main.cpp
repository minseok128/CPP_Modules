/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:21:27 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 18:54:57 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "WordChanger.hpp"

void	saveResult(std::string result, std::string originalName)
{
	std::ofstream	ofs(originalName.append(".result"));
	
	if (!ofs.is_open())
		throw (std::string("Can't write result file!"));
	ofs << result;
	ofs.close();
}

std::string	run(std::ifstream &ifs, std::string s1, std::string s2)
{
	WordChanger			wc;
	std::stringstream	buffer;
	std::string			totalStr;

	try
	{
		buffer << ifs.rdbuf();
		totalStr = buffer.str();
		wc.setTotalStr(totalStr);
		return (wc.changeWord(s1, s2));
	}
	catch (std::string &str)
	{
		throw (str);
	}
}

int	main(int argc, char **argv)
{
	std::ifstream ifs(argv[1]);

	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <fname> <s1> <s2>" << std::endl;
		return (1);
	}
		

	if (!ifs.is_open())
		std::cerr << "Can't open " << argv[1] << std::endl;
	else
	{
		try
		{
			saveResult(run(ifs, argv[2], argv[3]), argv[1]);
			std::cout << "Word Change Done!" << std::endl;
		}
		catch (std::string &str)
		{
			std::cerr << str << std::endl;
			ifs.close();
			return (1);
		}
		ifs.close();
	}
}