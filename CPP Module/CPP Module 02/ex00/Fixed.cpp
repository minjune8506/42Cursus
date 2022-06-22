#include "Fixed.hpp"
#include <iostream>

const int Fixed::frac = 8;

Fixed::Fixed() : fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(f.getRawBits());
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
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointNumber;
}

void Fixed::setRawBits(int const raw) {
	fixedPointNumber = raw;
}