/**
 * @file iterator.hpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief iterator header file
 * @date 2022-07-21
 */

#ifndef ITERATOR_BASE_HPP
# define ITERATOR_BASE_HPP

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
			typename Pointer = T*,
			typename Reference = T&>
struct iterator {
	typedef Category iterator_category;
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
};

/**
 * @brief Traits class defining properties of iterators.
 * 
 * @tparam Iterator 
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
 * 
 * @tparam T 
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
 * 
 * @tparam T 
 */
template <typename T>
struct iterator_traits<const T*> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef random_access_iterator_tag iterator_category;
};
}; // namespace ft

#endif
