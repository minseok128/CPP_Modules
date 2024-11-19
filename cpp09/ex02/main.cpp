/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:23 by michang           #+#    #+#             */
/*   Updated: 2024/11/19 19:50:51 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

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
}

int main(int argc, char** argv) {
	try {
		if (argc < 2)
			throw std::exception();
		buildOriginal(argc, argv);
	} catch (std::exception& e) {
		std::cerr << "Error" << std::endl;
		std::exit(1);
	}

	PmergeMe& pm = PmergeMe::getInstance();
	pm.printAll("Befor: ");

	clock_t startVector = clock();
	pm.sortVector();
	clock_t endVector = clock();
	double durationVector = static_cast<double>(endVector - startVector) /
							CLOCKS_PER_SEC * 1000000;

	clock_t startList = clock();
	pm.sortList();
	clock_t endList = clock();
	double durationList = static_cast<double>(endList - startList) /
						  CLOCKS_PER_SEC * 1000000;

	pm.printAll("After: ");
	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::vector : " << durationVector << " us"
			  << std::endl;
	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::list : " << durationList << " us"
			  << std::endl;

	if (pm.getVCoutn() != pm.getLCount())
		std::cerr << "Error: Vector count and List count are different"
				  << std::endl;

	std::exit(0);
}