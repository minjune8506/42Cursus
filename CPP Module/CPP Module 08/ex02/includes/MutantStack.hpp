#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack();
	MutantStack(const MutantStack &rhs);
	MutantStack &operator=(const MutantStack &rhs);
	~MutantStack();
	iterator begin();
	iterator end();
	iterator rbegin();
	iterator rend();
};

template <typename T>
MutantStack<T>::MutantStack() : MutantStack<T>::stack() {
	
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &rhs) : MutantStack<T>::stack(rhs) {

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs) {
	MutantStack<T>::stack::operator=(rhs);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {

}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();	
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rbegin() {
	return this->c.rbegin();	
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rend() {
	return this->c.rend();
}

#endif
