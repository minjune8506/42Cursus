#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
public:
	Character();
	Character(const std::string name);
	Character(const Character &obj);
	Character &operator=(const Character &obj);
	~Character();
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
private:
	AMateria *slot_[4];
	std::string name_;
};

#endif
