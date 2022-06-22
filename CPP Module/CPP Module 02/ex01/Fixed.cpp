#include "Fixed.hpp"
#include <iostream>

const int Fixed::frac = 8;

Fixed::Fixed() : fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x) {
	std::cout << "Int constructor called" << std::endl;
	fixedPointNumber = x << Fixed::frac;
}

Fixed::Fixed(const float x) {
	std::cout << "Float constructor called" << std::endl;
	fixedPointNumber = roundf(x * (1 << Fixed::frac));
}


Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	(*this) = f;
}

Fixed &Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator  called" << std::endl;
	this->setRawBits(f.getRawBits());
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return fixedPointNumber;
}

void Fixed::setRawBits(int const raw) {
	fixedPointNumber = raw;
}

float Fixed::toFloat(void) const {
	return (float)fixedPointNumber / (1 << Fixed::frac);
}

int Fixed::toInt(void) const {
	return fixedPointNumber >> 8;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	std::cout << f.toFloat();
	return out;
}