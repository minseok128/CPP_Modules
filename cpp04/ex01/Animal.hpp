#ifndef ANIMAL_CPP
# define ANIMAL_CPP
# include <iostream>
# include <string>

class Animal
{
public:
	Animal();
	Animal(const Animal& obj);
	Animal(const std::string& type);
	virtual				~Animal();
	Animal&				operator=(const Animal& obj);
	virtual void		makeSound() const;
	const std::string&	getType() const;

protected:
	std::string	_type;
};

#endif

