/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:30:59 by michang           #+#    #+#             */
/*   Updated: 2024/03/19 15:58:40 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& obj);
	~ClapTrap();
	ClapTrap&	operator=(const ClapTrap& obj);

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		getName() const;
	void			setName(const std::string &name);
	unsigned int	getHitPoints() const;
	void			setHitPoints(unsigned int hitPoints);
	unsigned int	getEnergyPoints() const;
	void			setEnergyPoints(unsigned int energyPoints);
	unsigned int	getAttackDamage() const;
	void			setAttackDamage(unsigned int attackDamage);

private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif
