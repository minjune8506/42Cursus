#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	/**
	 * @brief LIFO stack
	 * @tparam T Type of the elements.
	 * @tparam Container Type of the internal underlying container object where the elements are stored.
	 */
	template <typename T, typename Container = ft::vector<T> >
	class stack {
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;
		container_type c;
	public:
		/** Member functions **/
		explicit stack(const container_type &ctnr = container_type()) : c(ctnr) { }
		bool empty() const { return c.empty(); }
		size_type size() const { return c.size(); }
		value_type &top() { return c.back(); }
		const value_type &top() const { return c.back(); }
		void push (const value_type &val) { c.push_back(val); }
		void pop() { c.pop_back(); }
	};

	/** Non-member function overloads **/
	template <typename T, typename Container>
	bool operator== (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return lhs.c == rhs.c; }

	template <typename T, typename Container>
	bool operator<  (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return lhs.c < rhs.c; }

	template <typename T, typename Container>
	bool operator!= (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return !(lhs == rhs); }

	template <typename T, typename Container>
	bool operator<= (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return !(rhs < lhs); }

	template <typename T, typename Container>
	bool operator>  (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return rhs < lhs; }

	template <typename T, typename Container>
	bool operator>= (const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return !(lhs < rhs); }
} // namespace ft
#endif
