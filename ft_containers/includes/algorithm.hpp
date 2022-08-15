/**
 * @file algorithm.hpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief algorithms
 * @date 2022-07-23
 */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{
/**
 * @brief Copies the elements in the range [first,last) into the range beginning at result.
 * 
 * @param first Input iteratos to the initial position in a sequence to be copied.
 * @param last Input iterators to the final position in a sequence to be copied.
 * @param result Output iterator to the initial position in the destination sequence.
 * @return An iterator to the end of the destination range where elements have been copied.
 */
template <typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result) {
  while (first != last) {
    *result = *first;
    ++result; ++first;
  }
  return result;
}

/**
 * @brief Returns the largest of a and b. If both are equivalent, a is returned.
 * @return The largest of the values passed as arguments.
 */
template <class T>
const T &max(const T &a, const T &b) {
	return (a < b) ? b : a;
}

/**
 * @brief Exchanges the values of a and b.
 */
template <typename T>
void swap(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}

/**
 * @brief Test whether the elements in two ranges are equal
 * @param first1 Input iterators to the initial positions of the first sequence.
 * @param last1 Input iterators to the final positions of the first sequence.
 * @param first2 Input iterator to the initial position of the second sequence.
 * @return true true if all the elements in the range [first1,last1) compare equal to those of the range starting at first2, and false otherwise.
 */
template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
	while (first1 != last1) {
		if (!(*first1 == *first2))
			return false;
		++first1; ++first2;
	}
	return true;
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, BinaryPredicate pred) {
	while (first1 != last1) {
		if (!pred(*first1, *first2))
			return false;
		++first1; ++first2;
	}
	return true;
}

/**
 * @brief Lexicographical less-than comparison
 * Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
 * @param first1 @param last1 Input iterators to the initial and final positions of the first sequence.
 * @param first2 @param last2 Input iterators to the initial and final positions of the second sequence. 
 * @return true if the first range compares lexicographically less than the second. false otherwise
 */
template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
							InputIterator2 first2, InputIterator2 last2) {
	while (first1 != last1) {
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1; ++first2;
	}
	return (first2 != last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
  bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                            	InputIterator2 first2, InputIterator2 last2,
                                Compare comp) {
	while (first1 != last1) {
		if (first2 == last2 || comp(*first2, *first1))
			return false;
		else if (comp(*first1, *first2))
			return true;
		++first1; ++first2;
	}
	return (first2 != last2);
  }
} // namespace ft

#endif
