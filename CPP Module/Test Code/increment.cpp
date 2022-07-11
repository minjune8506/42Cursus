#include <iostream>

int main(void)
{
	int value = 1;

	// value = (value++)++;
	value = ++(++value);
	std::cout << value << std::endl;
}