/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:26:31 by michang           #+#    #+#             */
/*   Updated: 2024/03/30 16:29:54 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& obj);
	virtual ~ScavTrap();
	ScavTrap&	operator=(const ScavTrap& obj);

	void			guardGate();
	virtual void	attack(const std::string& target);
	virtual void	printInfo() const;

protected:
	static const unsigned int	S_ENERGY_POINTS;
	char						_isGatekeeperMode;
};

#endif
