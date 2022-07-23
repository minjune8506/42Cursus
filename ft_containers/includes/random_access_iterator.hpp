/**
 * @file random_access_iterator.hpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief random access iterator header file
 * @date 2022-07-21
 */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_base.hpp"

namespace ft
{
/**
 * @brief random_access_iterator
 * 
 * @tparam Iterator 
 * @tparam Container 
 */
template <typename Iterator, typename Container>
class random_access_iterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
										typename ft::iterator_traits<Iterator>::value_type,
										typename ft::iterator_traits<Iterator>::difference_type,
										typename ft::iterator_traits<Iterator>::pointer,
										typename ft::iterator_traits<Iterator>::reference>
{
protected:
	Iterator current;
public:
	typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
	typedef typename ft::iterator_traits<Iterator>::reference reference;
	typedef typename ft::iterator_traits<Iterator>::pointer pointer;

	random_access_iterator() : current(Iterator()) {}
	explicit random_access_iterator(const Iterator &i) : current(i) {}
	template <typename Iter>
	random_access_iterator(const random_access_iterator<Iter, Container> &i) : current(i.base()) {}

	// Forward iterator
	reference operator*() const { return *current; }
	pointer operator->() const { return current; }
	random_access_iterator &operator++() { ++current; return *this; }
	random_access_iterator operator++(int) { return random_access_iterator(current++); }
	
	// Bidirectional iterator
	random_access_iterator &operator--() { --current; return *this; }
	random_access_iterator operator--(int) { return random_access_iterator(current--); }

	// RandomAccess iterator
	reference operator[](const difference_type &n) const
	{ return current[n]; }
	random_access_iterator &operator+=(const difference_type &n)
	{ current += n; return *this; }
	random_access_iterator operator+(const difference_type &n) const
	{ return random_access_iterator(current + n); }
	random_access_iterator &operator-=(const difference_type &n)
	{ current -= n; return *this;}
	random_access_iterator operator-(const difference_type &n) const
	{ return random_access_iterator(current - n); }
	difference_type operator-(const random_access_iterator &i) const
	{ return current - i.current; }
	const Iterator &base() const
	{ return current; }
};

// Forward iterator requirements
template <typename IteratorL, typename IteratorR, typename Container>
bool operator==(const random_access_iterator<IteratorL, Container> &lhs,
				const random_access_iterator<IteratorR, Container> &rhs)
{ return lhs.base() == rhs.base(); }

template <typename IteratorL, typename IteratorR, typename Container>
bool operator!=(const random_access_iterator<IteratorL, Container> &lhs,
				const random_access_iterator<IteratorR, Container> &rhs)
{ return lhs.base() != rhs.base(); }

// Random access iterator requirements
template <typename IteratorL, typename IteratorR, typename Container>
bool operator<(const random_access_iterator<IteratorL, Container> &lhs,
				const random_access_iterator<IteratorL, Container> &rhs)
{ return lhs.base() < rhs.base(); }

template <typename IteratorL, typename IteratorR, typename Container>
bool operator>(const random_access_iterator<IteratorL, Container> &lhs,
				const random_access_iterator<IteratorL, Container> &rhs)
{ return lhs.base() > rhs.base(); }

template <typename IteratorL, typename IteratorR, typename Container>
bool operator<=(const random_access_iterator<IteratorL, Container> &lhs,
				const random_access_iterator<IteratorL, Container> &rhs)
{ return lhs.base() <= rhs.base(); }

template <typename IteratorL, typename IteratorR, typename Container>
bool operator>=(const random_access_iterator<IteratorL, Container> &lhs,
				const random_access_iterator<IteratorL, Container> &rhs)
{ return lhs.base() >= rhs.base(); }

template <typename Iterator, typename Container>
random_access_iterator<Iterator, Container> operator+(
		typename random_access_iterator<Iterator, Container>::difference_type n,
		const random_access_iterator<Iterator, Container> &i)
{ return random_access_iterator<Iterator, Container>(n + i.base()); }
}; // namespace ft

#endif
