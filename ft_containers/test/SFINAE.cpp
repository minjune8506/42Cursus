#include <iostream>

void foo(unsigned int i) {
	std::cout << "unsigned " << i << '\n';
}

template <typename T>
void foo(const T& t) {
	std::cout << "template " << t << '\n';
}

// SFINAE
int negate(int i) {
	return -i;
}

template <typename T>
typename T::value_type negate(const T& t) {
	return -T(t);
}
// Compiler가 후보를 확인하는 과정에서 template 인자 T를 int로 추론하게 되고
// int::value_type naegate(const int& t) 라는 말이 안되는 코드를 생성한다.
// 하지만 Error가 나지 않음

template <typename T>
void negate(const T& t) {
	typename T::valuetype n = -t();
}

int main() {
	foo(42); // template 42
	// 정수 리터럴의 경우 default로 signed가 되기 때문에 타입 변환이 필요없는 template을 사용하게 된다.
	foo(42U); // unsinged 42

	std::cout << negate(42) << std::endl;
}
