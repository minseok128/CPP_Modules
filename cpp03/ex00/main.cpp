/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:35:53 by michang           #+#    #+#             */
/*   Updated: 2024/03/19 15:36:27 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap("CL4P-TP");

	claptrap.attack("Enemy");

	claptrap.takeDamage(8);

	claptrap.beRepaired(5);

	claptrap.attack("Another Enemy");

	claptrap.takeDamage(4);

	claptrap.beRepaired(6);

	return 0;
}
