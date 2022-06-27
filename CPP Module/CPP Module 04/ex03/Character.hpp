#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
	Character();
	Character(const Character &obj);
	Character &operator=(const Character &obj);
	~Character();
private:
};

#endif