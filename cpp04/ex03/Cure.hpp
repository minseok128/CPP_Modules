#ifndef CURE_HPP
# define CURE_HPP
# include <string>
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& obj);
	~Cure();
	Cure&	operator=(const Cure& obj);
	AMateria*	clone() const;
	void		use(ICharacter& target);

private:

};

#endif
