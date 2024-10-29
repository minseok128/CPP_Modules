/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:09:54 by michang           #+#    #+#             */
/*   Updated: 2024/10/29 19:53:25 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int pintError(const std::string& error) {
	std::cerr << "Error: " << error << std::endl;
	return 1;
}

int main(int argc, char** argv) {
	std::ifstream inputFile(argv[1]);
	std::istringstream stream;
	std::string line, left, delimiter, right, error;

	if (argc != 2 && !inputFile.is_open()) {
		return pintError("could not open file.");
	} else {
		std::getline(inputFile, line);
		stream.str(line);
		stream.clear();
		if (!(stream >> left && left == "date" && stream >> delimiter &&
			  delimiter == "|" && stream >> right && right == "value" &&
			  !(stream >> right)))
			return pintError("could not open file.");
	}

	BitcoinExchange& exchange = BitcoinExchange::getInstance();
	exchange.initializeDatabase("data.csv");

	while (std::getline(inputFile, line)) {
		stream.str(line);
		stream.clear();

		if (!(stream >> left && stream >> delimiter && delimiter == "|" &&
			  stream >> right && !(stream >> right))) {
			pintError("bad input => " + line);
			continue;
		}

		error = exchange.calculatePrice(left, right);
		if (!error.empty())
			pintError(error);
	}

	BitcoinExchange::destroyInstance();
	return 0;
}