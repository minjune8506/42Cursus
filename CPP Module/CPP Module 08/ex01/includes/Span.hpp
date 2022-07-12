#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>

class Span {
public:
	Span();
	Span(unsigned int N);
	Span(const Span &rhs);
	Span &operator=(const Span &rhs);
	~Span();
	void addNumber(int num);
	void addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
	int shortestSpan();
	int longestSpan();
	class NoSpaceException : public std::exception {
	public:
		const char *what() const throw();
	};
	class CanNotFind : public std::exception {
	public:
		const char *what() const throw();
	};
private:
	std::vector<int> v;	
};

#endif
