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

	bool	operator>(const Fixed &f);
	bool	operator<(const Fixed &f);
	bool	operator>=(const Fixed &f);
	bool	operator<=(const Fixed &f);
	bool	operator==(const Fixed &f);
	bool	operator!=(const Fixed &f);
	
	Fixed	operator+(const Fixed &f);
	Fixed	operator+();
	Fixed	operator-(const Fixed &f);
	Fixed	operator-();
	Fixed	operator*(const Fixed &f);
	Fixed	operator/(const Fixed &f);

	Fixed	&operator++();
	const Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed &min(Fixed &x, Fixed &y);
	static const Fixed &min(const Fixed &x, const Fixed &y);
	static Fixed &max(Fixed &x, Fixed &y);
	static const Fixed &max(const Fixed &x, const Fixed &y);

private :
	int					fixedPointNumber;
	static const int	frac;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
#endif