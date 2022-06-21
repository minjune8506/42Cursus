#include <iostream>

int main(void)
{
	int value = 5;
	int &ref = value;

	std::cout << value << std::endl;
	value = 6;
	ref = 7;
	std::cout << "value : " << value << std::endl;
	std::cout << "ref : " << ref << std::endl;

	// int &invalidRef;
	// error: declaration of reference variable 'invalidRef' requires an initializer

	const int x = 10;
	// int &ref2 = x;
	// error: binding reference of type 'int' to value of type 'const int' drops 'const' qualifier
	// int &ref3 = 42;
	// error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'

	const int &ref2 = x; // Okay
	const int &ref3 = 42; // Okay

	// int &ref4 = value + value2;
	// error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
}