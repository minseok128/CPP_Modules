/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:10:50 by michang           #+#    #+#             */
/*   Updated: 2024/10/27 15:15:01 by michang          ###   ########.fr       */
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
	std::tm date = {}, origin = {};
	char delimiter;

	ss >> origin.tm_year >> delimiter >> origin.tm_mon >> delimiter >>
		origin.tm_mday;
	if (ss.fail() || delimiter != '-' || origin.tm_year < 1900)
		return 0;
	origin.tm_year -= 1900;
	origin.tm_mon -= 1;
	origin.tm_hour = 0;
	origin.tm_min = 0;
	origin.tm_sec = 0;
	date = origin;
	std::time_t tempTime = std::mktime(&origin);
	if (tempTime == -1)
		return 0;
	std::tm* validDate = std::localtime(&tempTime);
	if (!(validDate->tm_year == date.tm_year &&
		validDate->tm_mon == date.tm_mon && validDate->tm_mday == date.tm_mday))
		return 0;
	if (tempTime > 1648479600 || tempTime < 1230822000)
		return 0;
	return tempTime;
}

std::string BitcoinExchange::calculatePrice(const std::string& date,
											const std::string& amount) {
	float amount_f = std::atof(amount.c_str());

	if (amount_f < 0)
		return "not a positive number.";
	if (amount_f > 1000000000)
		return "too large a number.";

	std::time_t date_t = makeTime_t(date);
	if (date_t == 0)
		return "bad date => " + date;
	std::map<std::time_t, float>::iterator it = _database.lower_bound(date_t);
	std::cout << date << " => " << amount << " = "
			  << _database[it->first] * std::atof(amount.c_str()) << std::endl;
	return "";
}