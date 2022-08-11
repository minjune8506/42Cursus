#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> vct;

	vct.reserve(10);
	vct.resize(5);

	std::vector<int> vct2(vct);
	std::cout << "capacity : " << vct.capacity() << std::endl;
	std::cout << "size : " << vct.size() << std::endl;
	std::cout << "capacity : " << vct2.capacity() << std::endl;
	std::cout << "size : " << vct2.size() << std::endl;

	vct2 = vct;
	std::cout << "capacity : " << vct2.capacity() << std::endl;
	std::cout << "size : " << vct2.size() << std::endl;
}
