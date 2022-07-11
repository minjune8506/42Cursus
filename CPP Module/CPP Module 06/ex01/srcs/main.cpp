#include "Data.hpp"
#include <iostream>
#include <cstdlib>

int main(void) {
	srand(time(0));
	Data *ptr = new Data("random number", rand(), "created");
	ptr->print();

	uintptr_t p = serialize(ptr);
	Data *ptr2 = deserialize(p);
	ptr2->print();

	if (ptr == ptr2) {
		std::cout << "Same Pointer" << std::endl;
	}
	delete ptr;
}
