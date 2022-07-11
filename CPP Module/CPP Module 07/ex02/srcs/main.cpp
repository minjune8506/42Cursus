#include "Array.hpp"
#include <iostream>

class Test { // Test Class
public:
	Test &operator=(int data) {
		data_ = data;
		return (*this);
	}
	int getData() const {
		return data_;
	}
private:
	int data_;
};

int main(void) {
	std::cout << "=====Default Constructor Test=====" << std::endl;
	Array<char> test;
	std::cout << "size : " << test.size() << std::endl;
	try {
		test[0] = 1;
	} catch (std::exception &e) { // Exception
		std::cerr << e.what() << std::endl;
	}

	std::cout << "=====Copy Constructor Test=====" << std::endl;
	Array<int> a(10);
	for (int i = 0 ; i < 10 ; i++) {
		a[i] = i; // Subscript overloading test
	}
	Array<int> copy = a; // Copy Constructor
	for (int i = 0 ; i < 10 ; i++) {
		std::cout << copy[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "size : " << copy.size() << std::endl;

	std::cout << "=====Different Type Test=====" << std::endl;
	Array<char> c(10);
	// c = a; // Error

	std::cout << "=====Class Array Test=====" << std::endl;
	Array<Test> t(5);
	Test temp;
	for (int i = 0 ; i < 5 ; i++) {
		t[i] = temp;
	}
	for (int i = 0 ; i < 5 ; i++) {
		std::cout << t[i].getData() << ' ';
	}
	std::cout << std::endl;
}
