#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *ary, int length, void (*func)(T const &)) {
	for (int i = 0 ; i < length ; i++) {
		func(ary[i]);
	}
}

template <typename T>
void print(const T &element) {
	std::cout << element << std::endl;
}

#endif
