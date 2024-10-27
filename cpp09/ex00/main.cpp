/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:09:54 by michang           #+#    #+#             */
/*   Updated: 2024/10/26 20:11:02 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int inputError() {
	std::cout << "Error: input." << std::endl;
	return 1;
}

int main(int argc, char** argv) {
	std::ifstream inputFile(argv[1]);
	std::istringstream stream;
	std::string line, word;

	if (argc != 2 && !inputFile.is_open()) {
		return inputError();
	} else {
		std::getline(inputFile, line);
		stream.str(line);
		stream.clear();
		if (!(stream >> word && word == "date" && stream >> word &&
			  word == "|" && stream >> word && word == "value" &&
			  !(stream >> word)))
			return inputError();
	}

	BitcoinExchange& exchange = BitcoinExchange::getInstance();
	exchange.initializeDatabase("data.csv");

	return 0;
}