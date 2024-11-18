/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:23 by michang           #+#    #+#             */
/*   Updated: 2024/11/18 21:01:19 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void buildOriginal(int argc, char** argv) {
	PmergeMe& pm = PmergeMe::getInstance();

	for (int i = 1; i < argc; i++) {
		for (char* tmp = argv[i]; *tmp; tmp++)
			if (*tmp > '9' || *tmp < '0')
				throw std::exception();
		int num = std::atoi(argv[i]);
		if (num < 1)
			throw std::exception();
		pm.pushBack(num);
	}
	pm.printAll("Befor: ");
}

int main(int argc, char** argv) {
	try {
		if (argc < 2)
			throw std::exception();
		buildOriginal(argc, argv);
	} catch (std::exception& e) {
		std::cerr << "Error" << std::endl;
		exit(1);
	}

	PmergeMe& pm = PmergeMe::getInstance();
	pm.sortVector();
	pm.debugVector();
	pm.printAll("");

	exit(0);
}