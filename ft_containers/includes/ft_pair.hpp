/**
 * @file ft_pair.hpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief std::pair reimplementation
 * @date 2022-07-23
 */
#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
template <typename T1, typename T2>
struct pair {
	typedef typename T1 first_type;
	typedef typename T2 second_type;

	first_type first;
	second_type second;

	// default constructor
	pair() : first(T1()), second(T2()) { }
	// copy constructor
	template<typename U, typename V>
	pair(const pair<U,V> &pr) : first(pr.first), second(pr.second) { }
	// initialization constructor
	pair(const first_type& a, const second_type& b) : first(a), second(b) { }
	
	// operator=
	pair<T1, T2> &operator=(const pair<T1, T2> &pr) {
		first = pr.first;
		second = pr.second;
	}
};

// relational opearators
template <class T1, class T2>
bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return (lhs.first == rhs.first) && (lhs.second == rhs.second); }

template <class T1, class T2>
bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs == rhs); }

template <class T1, class T2>
bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

template <class T1, class T2>
bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs < lhs); }

template <class T1, class T2>
bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs < lhs; }

template <class T1, class T2>
bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs < rhs); }

// make_pair
template <class T1, class T2>
pair<T1,T2> make_pair(const T1 &x, const T2 &y) {
	return pair<T1, T2>(x, y);
}
}; // namespace ft

#endif
