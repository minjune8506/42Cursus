#include "easyfind.hpp"

const char *NotFoundException::what() const throw() {
	return "Not Found";
}
