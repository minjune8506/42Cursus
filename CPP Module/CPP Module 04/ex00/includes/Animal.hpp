#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class Animal {
public:
	Animal();
	Animal(const Animal &obj);
	Animal &operator=(const Animal &obj);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
protected:
	std::string type_;
};

#endif