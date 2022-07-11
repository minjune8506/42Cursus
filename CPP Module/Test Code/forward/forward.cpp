#include <iostream>
#include "A.hpp"
#include "B.hpp"

int main(void) {
	A a;
	B b;

	a.func(b);
	b.func(a);
}