#include <iostream>
#include <algorithm>
#include <memory>
#include <cstdlib>

class A {
public:
	int num;
	A() {
		std::cout << "constructor called" << std::endl;
	}
	~A() {
		std::cout << "destructor called" << std::endl;
	}
};

template<class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)
{
  while (first != last) {
    *result = *first;
    ++result; ++first;
  }
  return result;
}

int main(void) {
	// std::allocator<A> alloc_;
	// std::allocator<A>::pointer p_start;
	// std::allocator<A>::pointer p_end;
	// A a;

	// p_start = alloc_.allocate(10);
	// p_end = p_start;
	// for (int i = 0 ; i < 10 ; i++) {
		// alloc_.construct(p_end++, a);
	// }
	// ::copy(p_start + 5, p_start + 10, p_start + 3);
	
	A *a = new A[10];
	for (int i = 0 ; i < 10 ; i++) {
		a[i].num = i;
	}
	::copy(a + 5, a + 10, a + 3);
	for (int i = 0 ; i < 10 ; i++) {
		std::cout << a[i].num << std::endl;
	}
}
