#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon {
public:
	Weapon(std::string type);
	void setType(std::string type);
	const std::string &getType();
private:
	std::string type;
};

#endif