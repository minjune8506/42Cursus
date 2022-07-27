/**
 * @file random_access_iterator.hpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief random access iterator header file
 * @date 2022-07-21
 */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
/**
 * @brief random_access_iterator
 * @tparam Iterator 
 */
template <typename Iterator>
class random_access_iterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
										typename ft::iterator_traits<Iterator>::value_type,
										typename ft::iterator_traits<Iterator>::difference_type,
										typename ft::iterator_traits<Iterator>::pointer,
										typename ft::iterator_traits<Iterator>::reference>
{
public:
	typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
	typedef typename ft::iterator_traits<Iterator>::reference reference;
	typedef typename ft::iterator_traits<Iterator>::pointer pointer;
	typedef Iterator iterator_type;

protected:
	iterator_type current;

public:
	// Constructors
	random_access_iterator() : current(Iterator()) {}
	explicit random_access_iterator(const Iterator &i) : current(i) {}

	// Copy Constructor
	template <typename Iter>
	random_access_iterator(const random_access_iterator<Iter> &i) : current(i.base()) {}

	// Destructor
	virtual ~random_access_iterator() {}

	// Member Functions
	const iterator_type &base() const { return current; }

	// Forward Iterator Member Functions
	reference operator*() const { return *current; }
	pointer operator->() const { return current; }
	random_access_iterator &operator++() { ++current; return *this; }
	random_access_iterator operator++(int) { return random_access_iterator(current++); }
	
	// Bidirectional Iterator Member Functions
	random_access_iterator &operator--() { --current; return *this; }
	random_access_iterator operator--(int) { return random_access_iterator(current--); }

	// RandomAccess Iterator Member Functions
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

};

// Forward iterator requirements
template <typename IteratorL, typename IteratorR>
bool operator==(const random_access_iterator<IteratorL> &lhs,
				const random_access_iterator<IteratorR> &rhs)
{ return lhs.base() == rhs.base(); }

template <typename IteratorL, typename IteratorR>
bool operator!=(const random_access_iterator<IteratorL> &lhs,
				const random_access_iterator<IteratorR> &rhs)
{ return !(lhs == rhs); }

// Random access iterator requirements
template <typename IteratorL, typename IteratorR>
bool operator<(const random_access_iterator<IteratorL> &lhs,
				const random_access_iterator<IteratorR> &rhs)
{ return lhs.base() < rhs.base(); }

template <typename IteratorL, typename IteratorR>
bool operator>(const random_access_iterator<IteratorL> &lhs,
				const random_access_iterator<IteratorR> &rhs)
{ return rhs < lhs; }

template <typename IteratorL, typename IteratorR>
bool operator<=(const random_access_iterator<IteratorL> &lhs,
				const random_access_iterator<IteratorR> &rhs)
{ return !(rhs < lhs); }

template <typename IteratorL, typename IteratorR>
bool operator>=(const random_access_iterator<IteratorL> &lhs,
				const random_access_iterator<IteratorR> &rhs)
{ return !(lhs < rhs); }

template <typename Iterator>
random_access_iterator<Iterator> operator+(
		typename random_access_iterator<Iterator>::difference_type n,
		const random_access_iterator<Iterator> &i)
{ return random_access_iterator<Iterator>(i.base() + n); }

template <typename Iterator1, typename Iterator2>
typename random_access_iterator<Iterator1>::difference_type operator-(
				const random_access_iterator<Iterator2> &lhs,
				const random_access_iterator<Iterator1> &rhs)
{ return lhs.base() - rhs.base(); }
} // namespace ft

#endif
