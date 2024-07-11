/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:02:23 by michang           #+#    #+#             */
/*   Updated: 2024/07/11 21:15:40 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

Base* generate(void) {
	static int isInitialized = 0;

	if (!isInitialized) {
		std::srand(static_cast<unsigned int>(std::time(0)));
		isInitialized = 1;
	}

	switch (std::rand() % 3) {
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	}
	return (0);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "pointer of A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "pointer of B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "pointer of C" << std::endl;
	} else {
		std::cout << "Unknown" << std::endl;
		throw std::bad_alloc();
	}
}

void identify(Base& p) {
	try {
		Base tmp = dynamic_cast<A&>(p);
		std::cout << "referance of A" << std::endl;

	} catch (const std::exception& e) {
		try {
			Base tmp = dynamic_cast<B&>(p);
			std::cout << "referance of B" << std::endl;

		} catch (const std::exception& e) {
			try {
				Base tmp = dynamic_cast<C&>(p);
				std::cout << "referance of C" << std::endl;

			} catch (const std::exception& e) {
				std::cout << "Unknown" << std::endl;
				throw std::bad_alloc();
			}
		}
	}
}

int main() {
	try {
		for (int i = 0; i < 10; i++) {
			Base* first = generate();
			Base* second = generate();
			Base* third = generate();

			identify(first);
			identify(second);
			identify(third);

			identify(*first);
			identify(*second);
			identify(*third);

			delete first;
			delete second;
			delete third;
			std::cout << std::endl;
		}
	} catch (const std::bad_alloc& e) {
		std::cerr << e.what() << '\n';
		std::exit(1);
	}
	return (0);
}