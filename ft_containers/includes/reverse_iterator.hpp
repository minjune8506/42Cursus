/**
 * @file reverse_iterator.hpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief reverse iterator header file
 * @date 2022-07-21
 */
#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_base.hpp"

namespace ft
{
/**
 * @brief Reverse Iterator
 * This class reverses the direction in which a bidirectional or random-access iterator through a range.
 * @tparam Iterator bidirectional iterator type or a random-access iterator
 */
template <typename Iterator>
class reverse_iterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
										typename ft::iterator_traits<Iterator>::value_type,
										typename ft::iterator_traits<Iterator>::difference_type,
										typename ft::iterator_traits<Iterator>::pointer,
										typename ft::iterator_traits<Iterator>::reference>
{
protected:
	Iterator current;
public:
	typedef Iterator iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer pointer;
	typedef typename ft::iterator_traits<Iterator>::reference reference;
	
	// Constructors 
	
	reverse_iterator() { }
	explicit reverse_iterator(iterator_type it) : current(it) { }
	template <typename Iter>
	reverse_iterator(const reverse_iterator<Iter> &x) : current(x.base()) { }

	// Member Functions

	/**
	 * @brief Return base iterator.
	 * @return a copy of the base iterator.
	 */
	iterator_type base() const
	{ return current; }

	/**
	 * @brief Dereference iterator
	 * @return A reference to the element pointed by the iterator.
	 */
	reference operator*() const
	{ Iterator temp = current; return *--temp; }

	/**
	 * @brief Dereference iterator
	 * @return A pointer to the element pointed by the iterator.
	 */
	pointer operator->() const
	{ return &(operator*()); }

	/**
	 * @brief Pre-Increment iterator position
	 * @return reverse_iterator&
	 */
	reverse_iterator &operator++()
	{ --current; return *this; }

	/**
	 * @brief Post-Increment iterator position
	 * @return reverse_iterator
	 */
	reverse_iterator operator++(int) {
		reverse_iterator temp = *this;
		--current;
		return temp;
	}

	/**
	 * @brief Pre-Decreases the reverse_iterator by one position.
	 * @return reverse_iterator& 
	 */
	reverse_iterator &operator--()
	{ ++current; return *this; }

	/**
	 * @brief Post-Decreases the reverse_iterator by one position.
	 * @return reverse_iterator 
	 */
	reverse_iterator operator--(int) {
		reverse_iterator temp = *this;
		++current;
		return temp;
	}

	/**
	 * @brief Addition operator
	 * @param n 
	 * @return An iterator pointing to the element n positions away.
	 */
	reverse_iterator operator+(difference_type n) const
	{ return reverse_iterator(current - n); }

	/**
	 * @brief Advance iterator
	 * @param n Number of elements to offset.
	 * @return The reverse iterator itself (*this). 
	 */
	reverse_iterator &operator+=(difference_type n) const
	{ current -= n; return *this; }

	/**
	 * @brief Subtraction operator
	 * @param n Number of elements to offset.
	 * @return An iterator pointing to the element n positions before the currently pointed one. 
	 */
	reverse_iterator operator-(difference_type n) const 
	{ return reverse_iterator(current + n); }

	/**
	 * @brief Retrocede iterator
	 * @param n Number of elements to offset.
	 * @return The reverse iterator itself (*this). 
	 */
	reverse_iterator &operator-=(difference_type n) const
	{ current += n; return *this; }

	/**
	 * @brief Dereference iterator with offset
	 * Accesses the element located n positions away from the element currently pointed to by the iterator.
	 * If such an element does not exist, it causes undefined behavior.
	 * @param n Number of elements to offset.
	 * @return A reference to the element n positions away from the element currently pointed by the iterator. 
	 */
	reference operator[](difference_type n) const
	{ return *(*this + n); }
};

/**
 * @brief Relational operators for reverse_iterator
 * 
 * @tparam Iterator
 * @param lhs 
 * @param rhs 
 * @return true if the condition holds, and false otherwise.
 */
template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs)
{ return lhs.base() == rhs.base(); }

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs)
{ return lhs.base() != rhs.base(); }

template <class Iterator>
bool operator<(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs)
{ return lhs.base() < rhs.base(); }

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs)
{ return lhs.base() <= rhs.base(); }

template <class Iterator>
bool operator>(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs)
{ return lhs.base() > rhs.base(); }

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs)
{ return lhs.base() >= rhs.base(); }

/**
 * @brief Addition operator
 * Returns a reverse iterator pointing to the element located n positions away from the element pointed to by rev_it.
 * @tparam Iterator
 * @param n Number of elements to offset.
 * @param rev_it Reverse iterator.
 * @return An iterator pointing to the element n positions away from rev_it.
 */
template <class Iterator>
reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it)
{ return reverse_iterator<Iterator>(rev_it.base() - n); }

/**
 * @brief Subtraction operator
 * Returns the distance between lhs and rhs.
 * @tparam Iterator 
 * @param lhs 
 * @param rhs 
 * @return The number of elements between lhs and rhs.
 */
template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
{ return reverse_iterator<Iterator>(rhs.base() - lhs.base()); }
}; // namespace ft
#endif
