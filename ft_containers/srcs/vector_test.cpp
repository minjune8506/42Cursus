#include "container.hpp"
#include <iostream>
#include <list>

template <typename T>
void print_vector(TESTED_NAMESPACE::vector<T> v) {
	std::cout << "max_size : " << v.max_size() << std::endl;
	std::cout << "size : " << v.size() << std::endl;
	std::cout << "capacity : " << v.capacity() << std::endl;
	std::cout << "empty : " << v.empty() << std::endl;

	typename TESTED_NAMESPACE::vector<T>::iterator it = v.begin();
	typename TESTED_NAMESPACE::vector<T>::iterator ite = v.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		it++;
	}
}

template <typename T>
void print_vector_reverse(TESTED_NAMESPACE::vector<T> v) { // reverse iterator test
	std::cout << "max_size : " << v.max_size() << std::endl;
	std::cout << "size : " << v.size() << std::endl;
	std::cout << "capacity : " << v.capacity() << std::endl;
	std::cout << "empty : " << v.empty() << std::endl;

	typename TESTED_NAMESPACE::vector<T>::reverse_iterator it = v.rbegin();
	typename TESTED_NAMESPACE::vector<T>::reverse_iterator ite = v.rend();
	while (it != ite) {
		std::cout << *it << std::endl;
		it++;
	}
}

void construct_test() {
	TESTED_NAMESPACE::vector<int> v(100, 42); // fill constructor
	print_vector(v);

	std::list<int> lst;
	for (int i = 0 ; i < 100 ; i++) {
		lst.push_back(i);
	}
	TESTED_NAMESPACE::vector<int> range_v(lst.begin(), lst.end()); // range constructor
	print_vector(range_v);

	TESTED_NAMESPACE::vector<int> copy_v(range_v); // copy construct
	print_vector(copy_v);

	copy_v = v; // assign operator
	print_vector(copy_v);
	print_vector_reverse(copy_v); // reverse iterator
}

template <typename T>
void resize_test(TESTED_NAMESPACE::vector<T> v) {
	print_vector(v);
	v.resize(1000000000000);
	print_vector(v);
}


template <typename T>
void big_size_test(TESTED_NAMESPACE::vector<T> v) {
	std::cout << "max_size : " << v.max_size() << std::endl;
	try {
		v.reserve(v.max_size() + 100);
	} catch (std::exception &e) {
		// std::cout << e.what() << std::endl;
	}
}

int vector_test() {
	clock_t start = clock();

	TESTED_NAMESPACE::vector<int> v; // empty container constructor
	print_vector(v);
	construct_test();
	resize_test(v);
	big_size_test(v);

	clock_t end = clock();
	std::cout << "time : " << (float)(end - start) / CLOCKS_PER_SEC << std::endl;
	return (EXIT_SUCCESS);
}
