#ifndef MIN_HPP
# define MIN_HPP

template <typename T>
T &min(T &a, T &b) {
	return a < b ? a : b;
}

#endif
