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
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private :
	int					fixedPointNumber_;
	static const int	frac_;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
#endif