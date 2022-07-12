#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main(void) {
	std::cout << "=====Vector test=====" << std::endl;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try {
		std::cout << *easyfind(v, 2) << std::endl; // Success
		easyfind(v, 4); // Fail
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "=====Deque Test=====" << std::endl;
	std::deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	try {
		std::cout << *easyfind(dq, 1) << std::endl; // Success
		easyfind(dq, 4); // Fail
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "=====List Test=====" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	try {
		std::cout << *easyfind(lst, 1) << std::endl; // Success
		easyfind(lst, 4); // Fail
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
