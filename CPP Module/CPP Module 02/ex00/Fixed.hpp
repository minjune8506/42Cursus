#ifndef FIXED_H
# define FIXED_H

class Fixed {
public :
	Fixed();
	Fixed(const Fixed &f);
	Fixed &operator=(const Fixed &f);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

private :
	int fixedPointNumber;
	static const int frac;
};

#endif