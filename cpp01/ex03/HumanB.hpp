/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:28 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 15:14:08 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &weapon);

private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif
