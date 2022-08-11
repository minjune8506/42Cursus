#include "container.hpp"
#include "utility.hpp"
#include <iostream>

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, TESTED_NAMESPACE::pair<T1, T2> p) {
	std::cout << '(' << p.first << ", " << p.second << ")";
	return out;
}

template <typename T1, typename T2>
void pair_copy_test(TESTED_NAMESPACE::pair<T1, T2> p) {
	std::cout << "=====copy constructor test=====" << std::endl;

	TESTED_NAMESPACE::pair<int, int> copy_p = p; // Copy construct
	std::cout << "copy : " << copy_p << std::endl;
	if (p != copy_p) {
		std::cerr << "error : copy construct" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "=====assign operator test=====" << std::endl;
	TESTED_NAMESPACE::pair<int, int> assign_p; // Copy assign
	assign_p = p;
	std::cout << "assign : " << assign_p << std::endl;
	if (assign_p != p || assign_p != copy_p) {
		std::cerr << "error : assign operator" << std::endl;
		exit(EXIT_FAILURE);
	}
}

template <typename T1, typename T2>
void relational_operator_test(TESTED_NAMESPACE::pair<T1, T2> p1, TESTED_NAMESPACE::pair<T1, T2> p2) {
	std::cout << "=====relational operator test=====" << std::endl;
	std::cout << "p1 == p2 : " << (p1 == p2) << std::endl;
	std::cout << "p1 != p2 : " << (p1 != p2) << std::endl;
	std::cout << "p1 < p2 : " << (p1 < p2) << std::endl;
	std::cout << "p1 <= p2 : " << (p1 <= p2) << std::endl;
	std::cout << "p1 > p2 : " << (p1 > p2) << std::endl;
	std::cout << "p1 >= p2 : " << (p1 >= p2) << std::endl;
}

int pair_test() {
	TESTED_NAMESPACE::pair<int, int> p1 = TESTED_NAMESPACE::make_pair(10, 20); // Constructor
	pair_copy_test(p1);

	TESTED_NAMESPACE::pair<int, int> p2(20, 30);
	relational_operator_test(p1, p2);

	return (EXIT_SUCCESS);
}
