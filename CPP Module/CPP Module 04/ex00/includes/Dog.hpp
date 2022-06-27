#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &obj);
	Dog &operator=(const Dog &obj);
	~Dog();
	void makeSound() const;
};

#endif