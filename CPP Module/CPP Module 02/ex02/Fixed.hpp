#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
public :
	Fixed();
	Fixed(const int x);
	Fixed(const float x);
	Fixed(const Fixed &f);
	~Fixed();
	Fixed	&operator=(const Fixed &f);

	bool	operator>(const Fixed &f) const;
	bool	operator<(const Fixed &f) const;
	bool	operator>=(const Fixed &f) const;
	bool	operator<=(const Fixed &f) const;
	bool	operator==(const Fixed &f) const;
	bool	operator!=(const Fixed &f) const;
	
	Fixed	operator+(const Fixed &f) const;
	Fixed	&operator+();
	Fixed	operator-(const Fixed &f) const;
	Fixed	&operator-();
	Fixed	operator*(const Fixed &f) const;
	Fixed	operator/(const Fixed &f) const;

	Fixed	&operator++();
	Fixed	&operator--();
	const Fixed	operator++(int);
	const Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
	static Fixed &min(Fixed &x, Fixed &y);
	static const Fixed &min(const Fixed &x, const Fixed &y);
	static Fixed &max(Fixed &x, Fixed &y);
	static const Fixed &max(const Fixed &x, const Fixed &y);

private :
	int					fixedPointNumber_;
	static const int	frac_;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
#endif