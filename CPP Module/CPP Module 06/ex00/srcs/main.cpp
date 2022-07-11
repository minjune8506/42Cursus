#include "Convert.hpp"
#include <iostream>
#include <sstream>

bool checkArgument(std::string str) {
	int cntDot = 0;
	int cntFloat = 0;
	int cntMinus = 0;
	int cntPlus = 0;

	for (int i = 0 ; i < static_cast<int>(str.size()) ; i++) {
		if (str[i] == '.') {
			cntDot++;
		} else if (str[i] == 'f') {
			cntFloat++;
		} else if (str[i] == '-') {
			cntMinus++;
		} else if (str[i] == '+') {
			cntPlus++;
		}
	}
	if (cntDot > 1 || cntFloat > 1 || cntMinus > 1 || cntPlus > 1) {
		return (false);
	}
	if (cntMinus && cntPlus) {
		return (false);
	}
	return (true);
}

bool checkString(std::string str) {
	if (str.size() < 1) {
		return (false);
	}
	std::size_t pos = str.find_first_of("-+");
	if (pos != std::string::npos && pos != 0) {
		return (false);
	}
	return (true);
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Input Error" << std::endl;
		return (EXIT_FAILURE);
	}
	if (!checkArgument(av[1]) || !checkString(av[1])) {
		std::cerr << "Invalid Input" << std::endl;
		return (EXIT_FAILURE);
	}
	std::stringstream ss;
	ss.str(av[1]);
	Convert c(ss.str());
	c.print();
}
