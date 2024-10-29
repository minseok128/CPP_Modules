/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:10:39 by michang           #+#    #+#             */
/*   Updated: 2024/10/29 19:53:15 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
  public:
	static BitcoinExchange& getInstance();
	static void destroyInstance();
	int initializeDatabase(const std::string& dataFile);
	std::string calculatePrice(const std::string& date,
							   const std::string& amount);

  private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& obj);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& obj);
	static BitcoinExchange* instance;
	static std::time_t makeTime_t(const std::string& dateStr);

	std::map<std::time_t, float> _database;
	std::time_t _mindate, _maxdate;
};

#endif
