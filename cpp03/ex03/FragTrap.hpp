/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:26:31 by michang           #+#    #+#             */
/*   Updated: 2024/03/30 16:32:34 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& obj);
	virtual ~FragTrap();
	FragTrap&	operator=(const FragTrap& obj);

	void			highFivesGuys() const;
	virtual void	printInfo() const;

protected:
	static const unsigned int	F_HIT_POINTS;
	static const unsigned int	F_ATTACK_DAMAGE;
};

#endif
