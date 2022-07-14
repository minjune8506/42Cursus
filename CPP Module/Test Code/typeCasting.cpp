#include <iostream>
#include <cstring>
#include <string>
#include <limits>

int main(void) {
	std::cout << atoi("-01234") << std::endl;
	std::cout << atoi("0-1234") << std::endl;
	std::cout << atoi("-0000001234") << std::endl;
	std::cout << atoi("-111234") << std::endl;
	std::cout << atoi("-+-+111234") << std::endl;
	std::cout << atoi("2147483648") << std::endl;
	std::cout << isalpha('-') << std::endl;
	std::cout << isalpha('+') << std::endl;
	std::cout << std::stof("0.0") << std::endl;
	if (std::numeric_limits<float>::has_infinity) {
		std::cout << "float has infinite" << std::endl;
	}
	if (std::numeric_limits<float>::infinity() == std::numeric_limits<double>::infinity()) {
		std::cout << "Same" << std::endl;
	}
	float f = 42.42;
	char c = static_cast<char>(f);
	std::cout << c << std::endl;
} 
