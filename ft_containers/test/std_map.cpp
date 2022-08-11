#include <map>
#include <iostream>
#include <utility>

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, std::pair<T1, T2> p) {
	std::cout << "(" << p.first << ", " << p.second << ")";
	return out;
}

template <typename T1, typename T2>
void print(std::map<T1, T2> m) {
	typedef typename std::map<T1, T2>::iterator iterator;
	iterator it = m.begin();
	iterator ite = m.end();
	std::cout << "size : " << m.size() << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		it++;
	}
}


int main(void)
{
	std::map<int, int> m;
	
	m.insert(std::make_pair<int, int>(1, 3));
	m.insert(std::make_pair<int, int>(2, 6));
	m.insert(std::make_pair<int, int>(3, 9));
	m.insert(std::make_pair<int, int>(4, 12));
	m.insert(std::make_pair<int, int>(5, 15));
	print(m);
}
