#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal *ary[10];
	for (int k = 0 ; k < 6 ; k++) {
		if (k < 3)
			ary[k] = new Dog();
		else
			ary[k] = new Cat();
	}
	
	Dog *a = new Dog();
	Dog *b = new Dog(*a);
	Dog *c = new Dog();
	*c = *b;
	
	delete c;
	delete b;
	delete a;

	delete j;//should not create a leak
	delete i;

	for (int k = 0 ; k < 6 ; k++) {
		delete ary[k];
	}
	return 0;
}