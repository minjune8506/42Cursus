#include "Fixed.hpp"
#include <iostream>

const int Fixed::frac = 8;

Fixed::Fixed() : fixedPointNumber(0) {
}

Fixed::Fixed(const int x) {
	fixedPointNumber = x << Fixed::frac;
}

Fixed::Fixed(const float x) {
	fixedPointNumber = roundf(x * (1 << Fixed::frac));
}

Fixed::Fixed(const Fixed &f) {
	(*this) = f;
}

bool Fixed::operator>(const Fixed &f) {
	return (this->toFloat() > f.toFloat());
}

bool Fixed::operator<(const Fixed &f) {
	return (this->toFloat() < f.toFloat());
}

bool Fixed::operator>=(const Fixed &f) {
	return (this->toFloat() >= f.toFloat());
}

bool Fixed::operator<=(const Fixed &f) {
	return (this->toFloat() <= f.toFloat());
}

bool Fixed::operator==(const Fixed &f) {
	return (this->toFloat() == f.toFloat());
}

bool Fixed::operator!=(const Fixed &f) {
	return (this->toFloat() != f.toFloat());
}

Fixed Fixed::operator+(const Fixed &f) {
	return Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator+() {
	return Fixed(this->toFloat());
}

Fixed Fixed::operator-(const Fixed &f) {
	return Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator-() {
	return Fixed(-this->toFloat());
}

Fixed Fixed::operator*(const Fixed &f) {
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f) {
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed &Fixed::operator=(const Fixed &f) {
	this->setRawBits(f.getRawBits());
	return (*this);
}

Fixed &Fixed::operator++() {
	this->fixedPointNumber += 1;
	return (*this);
}

const Fixed Fixed::operator++(int) {
	Fixed temp = Fixed(this->fixedPointNumber);
	this->fixedPointNumber += 1;
	return (temp);
}

Fixed::~Fixed() {
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

Fixed &Fixed::min(Fixed &x, Fixed &y) {
	if (x.toFloat() >= y.toFloat())
		return (y);
	return (x);
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y) {
	if (x.toFloat() >= y.toFloat())
		return (y);
	return (x);
}

Fixed &Fixed::max(Fixed &x, Fixed &y) {
	if (x.toFloat() >= y.toFloat())
		return (x);
	return (y);
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y) {
	if (x.toFloat() >= y.toFloat())
		return (x);
	return (y);
}