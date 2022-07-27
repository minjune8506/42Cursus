/**
 * @file iterator.hpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief iterator header file
 * @date 2022-07-21
 */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft
{
/**
 * @brief Empty class to identify the category of an iterator as input iterator
 */
struct input_iterator_tag {};
/**
 * @brief Empty class to identify the category of an iterator as output iterator
 */
struct output_iterator_tag {};
/**
 * @brief Empty class to identify the category of an iterator as a forward iterator
 */
struct forward_iterator_tag : public input_iterator_tag {};
/**
 * @brief Empty class to identify the category of an iterator as a bidirectional iterator
 */
struct bidirectional_iterator_tag : public forward_iterator_tag {};
/**
 * @brief Empty class to identify the category of an iterator as a random-access iterator
 */
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

/**
 * @brief Iterator base class
 * 
 * @tparam Category Category to which the iterator belongs to
 * @tparam T Type of elements pointed by the iterator.
 * @tparam Distance Type to represent the difference between two iterators.
 * @tparam Pointer Type to represent a pointer to an element pointed by the iterator.
 * @tparam Reference Type to represent a reference to an element pointed by the iterator.
 */
template <typename Category,
			typename T,
			typename Distance = ptrdiff_t,
			typename Pointer = T *,
			typename Reference = T &>
struct iterator {
	typedef Category iterator_category;
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
};

/**
 * @brief Traits class defining properties of iterators.
 */
template <typename Iterator>
struct iterator_traits {
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
	typedef typename Iterator::iterator_category iterator_category;
};

/**
 * @brief Traits class defining properties of iterators. (T * specialization)
 */
template <typename T>
struct iterator_traits<T *> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference; 
	typedef random_access_iterator_tag iterator_category;
};

/**
 * @brief Traits class defining properties of iterators. (const T * specialization)
 */
template <typename T>
struct iterator_traits<const T*> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef random_access_iterator_tag iterator_category;
};

template <typename InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last) {
	typename ft::iterator_traits<InputIterator>::difference_type n = 0;
	while (first != last) {
		first++; n++;
	}
	return n;
}

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
public:
	typedef Iterator iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer pointer;
	typedef typename ft::iterator_traits<Iterator>::reference reference;

protected:
	iterator_type current;

public:	
	// Constructors 
	reverse_iterator() : current() { }
	explicit reverse_iterator(iterator_type it) : current(it) { }
	
	// Copy Constructor
	template <typename Iter>
	reverse_iterator(const reverse_iterator<Iter> &x) : current(x.base()) { }

	// Destructor
	virtual ~reverse_iterator() {}

	// Member Functions
	/**
	 * @brief Return base iterator.
	 * @return a copy of the base iterator.
	 */
	const iterator_type &base() const { return current; }

	/**
	 * @brief Dereference iterator
	 * @return A reference to the element pointed by the iterator.
	 */
	reference operator*() const { Iterator temp = current; return *--temp; }

	/**
	 * @brief Dereference iterator
	 * @return A pointer to the element pointed by the iterator.
	 */
	pointer operator->() const { return &(operator*()); }

	/**
	 * @brief Pre-Increment iterator position
	 * @return reverse_iterator&
	 */
	reverse_iterator &operator++() { --current; return *this; }

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
	reverse_iterator &operator--() { ++current; return *this; }

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
	reverse_iterator operator+(difference_type n) const { return reverse_iterator(current - n); }

	/**
	 * @brief Advance iterator
	 * @param n Number of elements to offset.
	 * @return The reverse iterator itself (*this). 
	 */
	reverse_iterator &operator+=(difference_type n) { current -= n; return *this; }

	/**
	 * @brief Subtraction operator
	 * @param n Number of elements to offset.
	 * @return An iterator pointing to the element n positions before the currently pointed one. 
	 */
	reverse_iterator operator-(difference_type n) const { return reverse_iterator(current + n); }

	/**
	 * @brief Retrocede iterator
	 * @param n Number of elements to offset.
	 * @return The reverse iterator itself (*this). 
	 */
	reverse_iterator &operator-=(difference_type n) { current += n; return *this; }

	/**
	 * @brief Dereference iterator with offset
	 * Accesses the element located n positions away from the element currently pointed to by the iterator.
	 * If such an element does not exist, it causes undefined behavior.
	 * @param n Number of elements to offset.
	 * @return A reference to the element n positions away from the element currently pointed by the iterator. 
	 */
	reference operator[](difference_type n) const { return *(*this + n); }
};

/**
 * @brief Relational operators for reverse_iterator
 * 
 * @tparam Iterator
 * @param lhs 
 * @param rhs 
 * @return true if the condition holds, and false otherwise.
 */
template <typename Iterator1, typename Iterator2>
inline bool operator==(const reverse_iterator<Iterator1> &lhs,
						const reverse_iterator<Iterator2> &rhs)
{ return lhs.base() == rhs.base(); }

template <typename Iterator1, typename Iterator2>
inline bool operator!=(const reverse_iterator<Iterator1> &lhs,
						const reverse_iterator<Iterator2> &rhs)
{ return !(lhs == rhs); }

template <typename Iterator1, typename Iterator2>
inline bool operator<(const reverse_iterator<Iterator1> &lhs,
						const reverse_iterator<Iterator2> &rhs)
{ return rhs.base() < lhs.base(); }

template <typename Iterator1, typename Iterator2>
inline bool operator<=(const reverse_iterator<Iterator1> &lhs,
						const reverse_iterator<Iterator2> &rhs)
{ return !(rhs < lhs); }

template <typename Iterator1, typename Iterator2>
inline bool operator>(const reverse_iterator<Iterator1> &lhs,
						const reverse_iterator<Iterator2> &rhs)
{ return rhs < lhs; }

template <typename Iterator1, typename Iterator2>
inline bool operator>=(const reverse_iterator<Iterator1> &lhs,
						const reverse_iterator<Iterator2> &rhs)
{ return !(lhs < rhs); }

/**
 * @brief Addition operator
 * Returns a reverse iterator pointing to the element located n positions away from the element pointed to by rev_it.
 * @tparam Iterator
 * @param n Number of elements to offset.
 * @param rev_it Reverse iterator.
 * @return An iterator pointing to the element n positions away from rev_it.
 */
template <typename Iterator>
reverse_iterator<Iterator> operator+(
	typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
{ return reverse_iterator<Iterator>(rev_it.base() - n); }

/**
 * @brief Subtraction operator
 * Returns the distance between lhs and rhs.
 * @tparam Iterator 
 * @param lhs 
 * @param rhs 
 * @return The number of elements between lhs and rhs.
 */
template <typename Iterator1, typename Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
		const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
{ return rhs.base() - lhs.base(); }
} // namespace ft

#endif
