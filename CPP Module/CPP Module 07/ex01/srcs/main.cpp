#include "iter.hpp"
#include <string>

int main(void) {
	int int_ary[] = {1, 2, 3, 4, 5};
	char char_ary[] = {'a', 'b', 'c', 'd', 'e'};
	std::string string_ary[] = {"hi", "hello", "bye"};

	iter(int_ary, 5, print);
	iter(char_ary, 5, print);
	iter(string_ary, 3, print);
}
