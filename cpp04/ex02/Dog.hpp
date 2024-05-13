#ifndef DOG_HPP
# define DOG_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog();
	Dog(const Dog& obj);
	~Dog();
	Dog&	operator=(const Dog& obj);
	void	makeSound() const;

private:
	Brain*	_brain;
};

#endif
