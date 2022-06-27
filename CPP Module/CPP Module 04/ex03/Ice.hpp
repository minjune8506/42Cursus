#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria {
public:
	Ice();
	Ice(const std::string name);
	Ice(const Ice &obj);
	Ice &operator=(const Ice &obj);
	~Ice();
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif