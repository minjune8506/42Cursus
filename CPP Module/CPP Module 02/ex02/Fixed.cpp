#include "Fixed.hpp"
#include <cmath>

const int Fixed::frac_ = 8;

Fixed::Fixed() : fixedPointNumber_(0) {
}

Fixed::Fixed(const int x) {
	fixedPointNumber_ = x << Fixed::frac_;
}

Fixed::Fixed(const float x) {
	fixedPointNumber_ = roundf(x * (1 << Fixed::frac_));
}

Fixed::Fixed(const Fixed &f) {
	(*this) = f;
}

Fixed::~Fixed() {

}

Fixed &Fixed::operator=(const Fixed &f) {
	fixedPointNumber_ = f.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &f) const {
	return (this->toFloat() > f.toFloat());
}

bool Fixed::operator<(const Fixed &f) const {
	return (this->toFloat() < f.toFloat());
}

bool Fixed::operator>=(const Fixed &f) const {
	return (this->toFloat() >= f.toFloat());
}

bool Fixed::operator<=(const Fixed &f) const {
	return (this->toFloat() <= f.toFloat());
}

bool Fixed::operator==(const Fixed &f) const {
	return (this->toFloat() == f.toFloat());
}

bool Fixed::operator!=(const Fixed &f) const {
	return (this->toFloat() != f.toFloat());
}

Fixed Fixed::operator+(const Fixed &f) const {
	return Fixed(this->toFloat() + f.toFloat());
}

Fixed &Fixed::operator+() {
	return (*this);
}

Fixed Fixed::operator-(const Fixed &f) const {
	return Fixed(this->toFloat() - f.toFloat());
}

Fixed &Fixed::operator-() {
	fixedPointNumber_ *= -1;
	return (*this);
}

Fixed Fixed::operator*(const Fixed &f) const {
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f) const {
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed &Fixed::operator++() {
	fixedPointNumber_ += 1;
	return (*this);
}

const Fixed Fixed::operator++(int) {
	Fixed temp = (*this);
	fixedPointNumber_ += 1;
	return (temp);
}

Fixed &Fixed::operator--() {
	fixedPointNumber_ -= 1;
	return (*this);
}

const Fixed Fixed::operator--(int) {
	Fixed temp = (*this);
	fixedPointNumber_ -= 1;
	return (temp);
}

int Fixed::getRawBits(void) const {
	return fixedPointNumber_;
}

void Fixed::setRawBits(int const raw) {
	fixedPointNumber_ = raw;
}

float Fixed::toFloat(void) const {
	return (float)fixedPointNumber_ / (1 << Fixed::frac_);
}

int Fixed::toInt(void) const {
	return fixedPointNumber_ >> 8;
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

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	std::cout << f.toFloat();
	return out;
}