#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "iterator.hpp"

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector {
private:
	typedef vector<T, Allocator> vector_type;

public:
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	// iterator
	// const_iterator
	// reverse_iterator
	// const_reverse_iterator
	// typedef iterator_traits<iterator>::difference_type difference_type;
	typedef ptrdiff_t differece_type;
	typedef size_t size_type;

	explicit vector(const allocator_type& alloc = allocator_type());
	explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
	template <typename InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	vector(const vector& x);
	~vector();
	vector& operator=(const vector& x);

	// Iterators
	// begin
	// end
	// rbegin
	// rend

	// Capacity
	size_type size() const;
	size_type max_size() const;
	void resize (size_type n, value_type val = value_type());
	size_type capacity() const;
	bool empty() const;
	void reserve (size_type n);

	// Element Access
	reference operator[] (size_type n);
	const_reference operator[] (size_type n) const;
	reference at (size_type n);
	const_reference at (size_type n) const;
	reference front();
	const_reference front() const;
    reference back();
	const_reference back() const;

	// Modifiers
	template <typename InputIterator>
	void assign (InputIterator first, InputIterator last);

	void assign (size_type n, const value_type& val);
	void push_back (const value_type& val);
	void pop_back();
	iterator insert (iterator position, const value_type& val);
	void insert (iterator position, size_type n, const value_type& val);

	template <typename InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last);

	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);
	void swap (vector& x);
	void clear();

	// Allocator
	/**
	 *	get_allocator()
	 *	return : allocator_type
	 *	description : Returns a copy of the allocator object associated with the vector.
	 */
	allocator_type get_allocator() const {
		return M_data_allocator;
	}
protected:
	allocator_type M_data_allocator;
	pointer M_start_;
	pointer M_finish_;
	pointer M_end_of_storage_;
	pointer M_allocate(size_type n) {
		return M_data_allocator.allocate(n);
	}
	void M_dallocate(pointer p, size_type n) {
		if (p)
			M_data_allocator.deallocate(p, n);
	}
};

// Non-member function overloads
template <typename T, typename Alloc>
  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <typename T, typename Alloc>
  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <typename T, typename Alloc>
  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <typename T, typename Alloc>
  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <typename T, typename Alloc>
  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <typename T, typename Alloc>
  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <typename T, typename Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif
