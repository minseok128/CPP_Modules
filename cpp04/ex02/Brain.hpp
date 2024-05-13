#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain& obj);
	~Brain();
	Brain&	operator=(const Brain& obj);
	const std::string&	getIdea(const int idx) const;
	void				setIdea(const int idx, const std::string& idea);

private:
	std::string	_ideas[100];
};

#endif
