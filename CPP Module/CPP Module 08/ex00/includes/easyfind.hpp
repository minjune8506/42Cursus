#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

class NotFoundException : public std::exception {
public:
	const char *what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &param, int val) {
	typename T::iterator it = std::find(param.begin(), param.end(), val);
	if (it == param.end())
		throw NotFoundException();
	return it;
}

#endif
