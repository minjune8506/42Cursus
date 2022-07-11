#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <class T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array &rhs);
	Array &operator=(const Array &rhs);
	~Array();
	T &operator[](int index);
	int size() const;
	class ArrayOutOfBounds : public std::exception {
		const char *what() const throw();
	};
private:
	T *ary_;
	int size_;
};

template<class T>
Array<T>::Array() : ary_(new T[0]), size_(0) {

}

template<class T>
Array<T>::Array(unsigned int n) : ary_(new T[n]), size_(static_cast<int>(n)) {
	for (int i = 0 ; i < size_ ; i++) {
		ary_[i] = 0;
	}
}

template<class T>
Array<T>::Array(const Array &rhs) : ary_(new T[rhs.size_]), size_(rhs.size_) {
	for (int i = 0 ; i < rhs.size_ ; i++) {
		ary_[i] = rhs.ary_[i];
	}
}

template<class T>
Array<T> &Array<T>::operator=(const Array &rhs) {
	delete ary_;
	ary_ = new T[rhs.size_];
	for (int i = 0 ; i < rhs.size_ ; i++) {
		ary_[i] = rhs.ary_[i];
	}
}

template<class T>
Array<T>::~Array() {
	delete ary_;
	ary_ = NULL;
}

template<class T>
T &Array<T>::operator[](int index) {
	if (index < 0 || index >= size_) {
		throw ArrayOutOfBounds();
	}
	return ary_[index];
}

template<class T>
int Array<T>::size() const {
	return size_;
}


template <class T>
const char *Array<T>::ArrayOutOfBounds::what() const throw() {
	return "Array Out Of Bounds";
}

#endif
