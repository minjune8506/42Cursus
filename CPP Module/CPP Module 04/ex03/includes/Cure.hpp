#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure &obj);
	Cure &operator=(const Cure &obj);
	~Cure();
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif
