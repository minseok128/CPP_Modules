/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:04:24 by michang           #+#    #+#             */
/*   Updated: 2024/03/30 16:21:00 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap A(std::string("A"));
	DiamondTrap B(std::string("B"));
	DiamondTrap C(A);
	std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	A.printInfo();
	B.printInfo();
	A.highFivesGuys();
	B.guardGate();
	A.whoAmI();
	B.whoAmI();

	return (0);
}