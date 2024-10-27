/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:10:50 by michang           #+#    #+#             */
/*   Updated: 2024/10/26 20:08:58 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange& BitcoinExchange::getInstance() {
	if (instance == 0)
	{
		instance = new BitcoinExchange();
		std::atexit(destroyInstance);
	}
	return *instance;
}

void BitcoinExchange::destroyInstance() {
	delete instance;
}

int BitcoinExchange::initializeDatabase(const std::string& dataFile) {
	_database.clear();
	std::ifstream inputFile(dataFile);
	std::istringstream stream;
	std::string line, date, value;

	if (!inputFile.is_open())
		return 1;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		stream.str(line);
		stream.clear();
		if (std::getline(stream, date, ',') && std::getline(stream, value, ','))
			return 1;
		_database[date] = std::stod(value);
	}

	for (std::map<std::string, double>::iterator it = _database.begin(); it != _database.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	return 0;
}