#ifndef A_H
# define A_H

#include <iostream>

class B;

class A {
public :
	A() {
		std::cout << "A!" << std::endl;
	}
	void func(B b);
};
#endif