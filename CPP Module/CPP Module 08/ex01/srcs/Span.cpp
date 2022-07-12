#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span() {
}

Span::Span(unsigned int N) {
	v.reserve(N);
}

Span::Span(const Span &rhs) : v(rhs.v) {

}

Span &Span::operator=(const Span &rhs) {
	v = rhs.v;
	return (*this);
}

Span::~Span() {

}

void Span::addNumber(int num) {
	if (v.size() == v.capacity()) {
		throw NoSpaceException();
	}
	v.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end) {
	std::vector<int>::iterator it = begin;
	if (v.size() == v.capacity()) {
		throw NoSpaceException();
	}
	while (it != end) {
		v.push_back(*it);
		if (v.size() == v.capacity()) {
			break ;
		}
		it++;
	}
}

int Span::longestSpan() {
	if (v.size() <= 1) {
		throw CanNotFind();
	}
	return *std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end());
}

int Span::shortestSpan() {
	if (v.size() <= 1) {
		throw CanNotFind();
	}
	std::sort(v.begin(), v.end());
	int shortest = v[1] - v[0];
	for (size_t i = 0 ; i < v.size() - 1 ; i++) {
		if (shortest > v[i + 1] - v[i]) {
			shortest = v[i + 1] - v[i];
		}
	}
	return shortest;
}

const char *Span::NoSpaceException::what() const throw() {
	return "No Space";
}

const char *Span::CanNotFind::what() const throw() {
	return "Can't find";
}
