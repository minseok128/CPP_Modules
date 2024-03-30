/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:04:24 by michang           #+#    #+#             */
/*   Updated: 2024/03/30 15:05:39 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main()
{
	FragTrap A(std::string("A"));
	FragTrap B(std::string("B"));
	std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	A.printInfo();
	B.printInfo();

	A.highFivesGuys();
	B.highFivesGuys();

	return (0);
}
