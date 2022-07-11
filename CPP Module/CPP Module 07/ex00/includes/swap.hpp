#ifndef SWAP_HPP
# define SWAP_HPP

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

#endif
