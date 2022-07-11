#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base *generate(void) {
	int choice = rand() % 3;
	if (choice == 0) {
		return new A();
	} else if (choice == 1) {
		return new B();
	} else {
		return new C();
	}
}

void identify(Base* p) {
	try {
 		A &ref_A = dynamic_cast<A &>(*p);
 		std::cout << "type is A" << std::endl;
 		(void)ref_A;
 	} catch (std::exception &e) {
	 }

 	try {
 		B &ref_B = dynamic_cast<B &>(*p);
 		std::cout << "type is B" << std::endl;
 		(void)ref_B;
 	} catch (std::exception &e) {
	 }

 	try {
 		C &ref_C = dynamic_cast<C &>(*p);
 		std::cout << "type is C" << std::endl;
 		(void)ref_C;
 	} catch (std::exception &e) {
	 }
}

void identify(Base& p) {
	A *ptr_A = dynamic_cast<A *>(&p);
	B *ptr_B = dynamic_cast<B *>(&p);
	C *ptr_C = dynamic_cast<C *>(&p);

	std::cout << "type is ";
	if (ptr_A) { 
		std::cout << "A" << std::endl;
		return ;
	} else if (ptr_B) {
		std::cout << "B" << std::endl;
		return ;
	} else if (ptr_C) {
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Undefined" << std::endl;
}

int main(void) {
	srand(time(0));
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
}
