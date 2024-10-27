/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:10:39 by michang           #+#    #+#             */
/*   Updated: 2024/10/26 20:08:38 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
  public:
	static BitcoinExchange& getInstance();
	int initializeDatabase(const std::string& dataFile);

  private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& obj);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& obj);
	static BitcoinExchange* instance;
	static void destroyInstance();

	std::map<std::string, double> _database;
};

#endif
