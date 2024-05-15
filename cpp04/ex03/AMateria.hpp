#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class AMateria
{
public:
	AMateria();
	AMateria(const AMateria& obj);
	AMateria(const std::string& type);
	~AMateria();
	AMateria&			operator=(const AMateria& obj);
	const std::string&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

protected:
	std::string	_type;

};

#endif
