#include <vector>
#include <iostream>

int main(void) {
	std::vector<int> v(10, 20);

	std::cout << std::endl;
	for (auto it = v.begin() ; it != v.end() ; it++) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	try {
		v.at(10);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		v.reserve(v.max_size() + 10);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
