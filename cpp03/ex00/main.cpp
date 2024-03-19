/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:35:53 by michang           #+#    #+#             */
/*   Updated: 2024/03/19 16:02:00 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main() {
	ClapTrap	claptrap1("CL4P-TP1");
	ClapTrap	claptrap2("CL4P-TP2");

	// 서로 공격 시나리오
	std::cout << "\n=== Battle Begins ===" << std::endl;
	claptrap1.attack(claptrap2.getName());
	claptrap2.takeDamage(claptrap1.getAttackDamage());
	claptrap2.attack(claptrap1.getName());
	claptrap1.takeDamage(claptrap2.getAttackDamage());

	// 상태 회복 시나리오
	std::cout << "\n=== Recovery Time ===" << std::endl;
	claptrap1.beRepaired(5);
	claptrap2.beRepaired(5);

	// 에너지 소진 시나리오
	std::cout << "\n=== Energy Drain ===" << std::endl;
	for (int i = 0; i < 12; ++i)
		claptrap1.attack(claptrap2.getName());

	// 큰 피해 시나리오
	std::cout << "\n=== Critical Damage ===" << std::endl;
	claptrap2.takeDamage(20);
	std::cout << claptrap2.getName() << " has " << claptrap2.getHitPoints() << " hit points." << std::endl;

	// 수리 시도, 에너지 없음
	std::cout << "\n=== Attempt Repair Without Energy ===" << std::endl;
	claptrap2.beRepaired(10);

	return (0);
}