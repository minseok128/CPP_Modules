#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "Floor.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(const Character& obj);
	Character(const std::string& name);
	~Character();
	Character&			operator=(const Character& obj);
	const std::string&	getName() const;
	void				setFloor(Floor* floor);
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria*	_inventory[4];
	Floor*		_floor;
};

#endif
