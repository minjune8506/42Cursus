#include <iostream>

void changeN(int &ref) {
	ref = 6;
}

int main(void)
{
	int n = 5;
	changeN(n);
	std::cout << n << std::endl;	
}