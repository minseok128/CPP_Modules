/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:41:36 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 14:45:22 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
public:
	Weapon();
	~Weapon();
	const std::string	&getType() const;
	void				setType(std::string type);

private:
	std::string	_type;
};

#endif