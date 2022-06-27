#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include <string>

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure &obj);
	Cure &operator=(const Cure &obj);
	~Cure();
private:
	std::string type;
};

#endif