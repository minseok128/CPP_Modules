/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:02:28 by michang           #+#    #+#             */
/*   Updated: 2024/07/12 20:01:30 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// void leaks_check() {
// 	std::cout << "leaks check\n";
// 	system("leaks --list a.out");
// }

#define MAX_VAL 750
int main(int, char**) {
	// atexit(leaks_check);
	{
		std::cout << "--Subject test\n";
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		std::srand(std::time(NULL));
		for (int i = 0; i < MAX_VAL; i++) {
			const int value = std::rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		// SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}

		try {
			numbers[-2] = 42;
			std::cout << numbers[-2] << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		try {
			numbers[MAX_VAL] = 42;
			std::cout << numbers[MAX_VAL] << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		try {
			numbers[MAX_VAL - 1] = 42;
			std::cout << numbers[MAX_VAL - 1] << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		delete[] mirror;
	}

	{
		std::cout << "\n--Additional test\n";

		std::cout << "-constructor test\n";
		Array<int> arrNull;
		Array<int> arrZero(0);
		try {
			arrNull[0] = 1;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		try {
			arrZero[0] = 1;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		std::cout << "\n-basic test\n";
		Array<std::string> arr(5);
		arr[0] = "1st element";
		arr[1] = "2nd element";
		arr[2] = "3rd element";
		arr[3] = "4th element";
		arr[4] = "5th element";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << std::endl;

		std::cout << "\n-copy constructor test\n";
		Array<std::string> copy(arr);
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << std::endl;

		std::cout << "\n-copy assignment operator test\n";
		Array<std::string> copyOp;
		copyOp = copy;
		for (unsigned int i = 0; i < copyOp.size(); i++)
			std::cout << copyOp[i] << std::endl;

		std::cout << "\n-const test\n";
		const Array<std::string> arrConst(arr);
		for (unsigned int i = 0; i < arrConst.size(); i++)
			std::cout << arrConst[i] << std::endl;
	}

	return 0;
}