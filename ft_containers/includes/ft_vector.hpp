/**
 * @file vector.hpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief Vector Implementation
 * @date 2022-07-21
 */
#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"

#include <memory>
#include <stdexcept>
#include <cassert>

namespace ft {

template <typename T, typename Alloc = std::allocator<T> >
class vector {
private:
	typedef vector<T, Alloc> vector_type;

public:
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef ft::random_access_iterator<pointer, vector_type> iterator;
	typedef ft::random_access_iterator<const_pointer, vector_type> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef ptrdiff_t differece_type;
	typedef size_t size_type;

protected:
	allocator_type M_data_allocator;
	pointer M_start_;
	pointer M_finish_;
	pointer M_end_of_storage_;

public:
	explicit vector(const allocator_type& alloc = allocator_type())
	: M_data_allocator(alloc), M_start_(0), M_finish_(0), M_end_of_storage_(0) { }

	explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	: M_data_allocator(alloc) {
		M_start_ = M_data_allocator.allocate(n);
		M_finish_ = M_start_;
		M_end_of_storage_ = M_start_ + n;
		while (n--)
			M_data_allocator.construct(M_finish_++, val);
	}
	
	template <typename InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::Integral::value>::type* = 0)
		: M_data_allocator(alloc) {
		size_type n = last - first;
		M_start_ = M_data_allocator.allocate(n);
		M_finish_ = M_start_;
		M_end_of_storage_ = M_start_ + n;
		while (n--)
			M_data_allocator.construct(M_finish_++, *first++);
	}

	vector(const vector<T, Alloc>& x) : M_data_allocator(x.M_data_allocator) {
		size_type n = x.size();
		M_start_ = M_data_allocator.allocate(n);
		M_finish_ = M_start_;
		M_end_of_storage_ = M_start_ + n;
		pointer x_start = x.M_start_;
		while (n--)
			M_data_allocator.construct(M_finish_++, *x_start++);
	}

	~vector() {
		clear();
		M_data_allocator.deallocate(M_start_, capacity());
	}

	vector_type& operator=(const vector_type& x); // TODO copy assignment operator

	// Iterators
	iterator begin() { return iterator(M_start_); }
	const_iterator begin() const { return const_iterator(M_start_); }
	iterator end() { return iterator(M_finish_); }
	const_iterator end() const { return const_iterator(M_finish_); }
    reverse_iterator rbegin() { return reverse_iterator(end()); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
	reverse_iterator rend() { return reverse_iterator(begin()); }
	const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

	// Capacity
	size_type size() const { return size_type(end() - begin()); }
	size_type max_size() const { return M_data_allocator.max_size(); }
	void resize (size_type n, value_type val = value_type()); // TODO - resize
	size_type capacity() const { return size_type(M_end_of_storage_ - M_start_); }
	bool empty() const { return begin() == end(); }
	void reserve (size_type n) { // FIXME - reserve
		if (n > max_size()) {
			throw std::length_error("vector");
		}
		if (capacity() < n) {
			pointer prev_start = M_start_;
			pointer prev_finish = M_finish_;
			pointer prev_end_of_storage = M_end_of_storage_;
			size_type length = capacity();

			M_start_ = M_data_allocator.allocate(n);
			M_end_of_storage_ = M_start_ + n;
			M_finish_ = M_start_;
			for (pointer it = prev_start ; it != prev_end_of_storage ; ++it) {
				M_data_allocator.construct(M_finish_++, *it);
			}
			for (pointer it = prev_finish ; it != prev_start ; it--) {
				M_data_allocator.destroy(it);
			}
			M_data_allocator.deallocate(prev_start, length);
		}
	}

	// Element Access
	reference operator[](size_type n) { return *(begin() + n); }
	const_reference operator[](size_type n) const { return *(begin() + n); }
	reference at(size_type n) {
		if (n >= size()) {
			throw std::out_of_range("vector");
		}
		return (*this)[n];
	}
	const_reference at(size_type n) const {
		if (n >= size()) {
			throw std::out_of_range("vector");
		}
		return (*this)[n];
	}
	reference front() {
		return *begin();
	}
	const_reference front() const {
		return *begin();
	}
    reference back() {
		return *(end() - 1);
	}
	const_reference back() const {
		return *(end() - 1);
	}

	// Modifiers
	template <typename InputIterator>
	void assign (InputIterator first, InputIterator last); // TODO - assign
	void assign (size_type n, const value_type& val); // TODO - assign
	void push_back (const value_type& val) {
		if (M_finish_ == M_end_of_storage_) {
			size_type data_capacity = (capacity() == 0) ? 1 : capacity() * 2;
			reserve(data_capacity);
		}
		M_data_allocator.construct(M_finish_++, val);	
	}
	void pop_back() {
		M_data_allocator.destroy(--M_finish_);
	}
	iterator insert (iterator position, const value_type& val); // TODO - insert
	void insert (iterator position, size_type n, const value_type& val); // TODO - insert
	template <typename InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last); // TODO - insert
	iterator erase (iterator position); // TODO - erase
	iterator erase (iterator first, iterator last); // TODO - erase
	void swap (vector& x); // TODO - swap
	void clear() {
		while (M_start_ != M_finish_) {
			M_data_allocator.destroy(M_finish_);
			M_finish_--;
		}
	}

	// Alloc
	allocator_type get_allocator() const {
		return M_data_allocator;
	}
};

// Non-member function overloads
// TODO - realational operator
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
} // namespace ft

#endif
