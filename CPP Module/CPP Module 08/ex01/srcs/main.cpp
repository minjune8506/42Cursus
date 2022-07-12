#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void) {
	std::cout << "=====test1=====" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "=====test2=====" << std::endl;
	std::vector<int> v;
	for (int i = 0 ; i < 100000 ; i++) {
		v.push_back(i);
	}
	Span sp2(100000);
	sp2.addNumber(v.begin(), v.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	return 0;
}
