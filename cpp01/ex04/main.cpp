/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:21:27 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 16:17:14 by michang          ###   ########.fr       */
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
	std::ofstream	ofile(originalName.append(".result"));
	
	if (ofile.is_open())
	{
		ofile << result;
		ofile.close();
	}
	else
		throw (std::logic_error("Can't write result file!"));
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
		ifs.close();
		wc.setTotalStr(totalStr);
		return (wc.changeWord(s1, s2));
	}
	catch (std::exception &e)
	{
		throw (e);
	}
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
	{
		try
		{
			saveResult(run(ifs, argv[2], argv[3]), argv[1]);
			std::cout << "Word Change Done!" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}