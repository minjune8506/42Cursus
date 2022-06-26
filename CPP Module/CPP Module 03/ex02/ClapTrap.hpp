#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &obj);
	ClapTrap &operator=(const ClapTrap &obj);
	~ClapTrap();
	int		getAttackDamage();
	void	setAttackDamage(int attackDamage);
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
protected:
	std::string	name_;
	int			hitPoints_;
	int			energyPoints_;
	int			attackDamage_;
};

#endif
