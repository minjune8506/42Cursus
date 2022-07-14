#include <iostream>

template <typename T>
T add(T a, T b) {
	return a + b;
}

// 명시적 특수화
template<>
float add(float a, float b) {
	std::cout << "Float Template Called" << std::endl;
	return a - b;
}

int main(void) {
	std::cout << add(1, 2) << std::endl;
	std::cout << add(1.0f, 2.0f) << std::endl;
}
