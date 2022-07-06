#include <iostream>
#include <cstring>
#include <string>

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

	float f = 42.42;
	char c = static_cast<char>(f);
	std::cout << c << std::endl;
} 