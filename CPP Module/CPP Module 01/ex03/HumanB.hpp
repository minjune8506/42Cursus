#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB {
public :
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack();
private :
	Weapon *weapon_;
	std::string name;
};

#endif