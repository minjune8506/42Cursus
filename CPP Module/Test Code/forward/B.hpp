#ifndef B_H
# define B_H

#include <iostream>

class A;

class B {
public:
	B() {
		std::cout << "B!" << std::endl;
	}
	void func(A a);
};

#endif