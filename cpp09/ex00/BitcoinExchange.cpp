/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:10:50 by michang           #+#    #+#             */
/*   Updated: 2024/10/27 14:33:48 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange* BitcoinExchange::instance = 0;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::getInstance() {
	if (instance == 0) {
		instance = new BitcoinExchange();
		std::atexit(destroyInstance);
	}
	return *instance;
}

void BitcoinExchange::destroyInstance() { delete instance; }

int BitcoinExchange::initializeDatabase(const std::string& dataFile) {
	_database.clear();
	std::ifstream inputFile(dataFile.c_str());
	std::string line, value;
	std::time_t date;

	if (!inputFile.is_open())
		return 1;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		if (line[10] != ',')
			return 1;
		date = makeTime_t(line.substr(0, 10));
		value = line.substr(11);
		if (date == 0 || value.empty())
			return 1;
		_database[date] = std::atof(value.c_str());
	}

	// std::cout << "Database initialized." << std::endl;
	// for (std::map<std::time_t, float>::iterator it = _database.begin();
	// 	 it != _database.end(); it++)
	// 	std::cout << it->first << " " << it->second << std::endl;
	return 0;
}

std::time_t BitcoinExchange::makeTime_t(const std::string& dateStr) {
	std::istringstream ss(dateStr);
	std::tm date = {};
	char delimiter;

	ss >> date.tm_year >> delimiter >> date.tm_mon >> delimiter >> date.tm_mday;
	if (ss.fail() || delimiter != '-' || date.tm_year < 1900)
		return 0;
	date.tm_year -= 1900;
	date.tm_mon -= 1;
	date.tm_hour = 0;
	date.tm_min = 0;
	date.tm_sec = 0;

	std::time_t tempTime = std::mktime(&date);
	if (tempTime == -1)
		return 0;

	std::tm* validDate = std::localtime(&tempTime);
	if (!(validDate->tm_year == date.tm_year &&
		  validDate->tm_mon == date.tm_mon &&
		  validDate->tm_mday == date.tm_mday))
		return 0;
	return tempTime;
}