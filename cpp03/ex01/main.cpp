/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:35:53 by michang           #+#    #+#             */
/*   Updated: 2024/03/30 13:35:22 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

#include "ScavTrap.hpp"

int main()
{
	ScavTrap A(std::string("A"));
	ScavTrap B(std::string("B"));
	std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	A.printInfo();
	B.printInfo();

	A.guardGate();
	B.guardGate();
	A.printInfo();
	B.printInfo();
	A.guardGate();

	return (0);
}