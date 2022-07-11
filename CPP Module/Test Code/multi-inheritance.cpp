#include <iostream>

class A {
public :
	int x = 1;
};

class B {
public :
	int x = 2;
};

class C : public A, public B {
public :
	int y;
};

int main(void) {
	C c;

	std::cout << c.A::x << std::endl;
	std::cout << c.B::x << std::endl;
}