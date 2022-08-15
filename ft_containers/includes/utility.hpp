/**
 * @file utility.hpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief std::pair reimplementation
 * @date 2022-07-23
 */
#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
/**
 * @brief This class couples together a pair of values, which may be of different types (T1 and T2).
 * @tparam T1 Type of member first, aliased as first_type.
 * @tparam T2 Type of member second, aliased as second_type.
 */
template <typename T1, typename T2>
struct pair {
	typedef T1 first_type;
	typedef T2 second_type;

	first_type first;
	second_type second;

	// Constructors
	pair() : first(T1()), second(T2()) { }
	pair(const first_type &a, const second_type &b) : first(a), second(b) { }
	
	// Copy Constructor
	template<typename U, typename V>
	pair(const pair<U,V> &pr) : first(pr.first), second(pr.second) { }
	
	// Destructor
	virtual ~pair() { };
};

// Relational Opearators
template <class T1, class T2>
bool operator==(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{ return (lhs.first == rhs.first) && (lhs.second == rhs.second); }

template <class T1, class T2>
bool operator!=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{ return !(lhs == rhs); }

template <class T1, class T2>
bool operator<(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

template <class T1, class T2>
bool operator<=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{ return !(rhs < lhs); }

template <class T1, class T2>
bool operator>(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{ return rhs < lhs; }

template <class T1, class T2>
bool operator>=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{ return !(lhs < rhs); }

/**
 * @brief Constructs a pair object with its first element set to x and its second element set to y.
 * @return A pair object whose elements first and second are set to x and y respectivelly.
 */
template <class T1, class T2>
pair<T1,T2> make_pair(const T1 &x, const T2 &y)
{ return pair<T1, T2>(x, y); }
} // namespace ft

#endif
