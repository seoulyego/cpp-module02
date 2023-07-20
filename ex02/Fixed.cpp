#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
};

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->value = num << this->bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	this->value = num * (1 << this->bits);
}

Fixed::Fixed(const Fixed& object) {
	std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed&	Fixed::operator=(const Fixed& object) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &object) {
		this->value = object.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	;
}

int	Fixed::getRawBits(void) const {
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

int	Fixed::toInt(void) const {
	return this->value >> this->bits;
}

float	Fixed::toFloat(void) const {
	return ((float)this->value / (1 << this->bits));
}

bool	Fixed::operator>(const Fixed& ref) const {
	return this->getRawBits() > ref.getRawBits();
}

bool	Fixed::operator<(const Fixed& ref) const {
	return this->getRawBits() < ref.getRawBits();
}

bool	Fixed::operator>=(const Fixed& ref) const {
	return this->getRawBits() >= ref.getRawBits();
}

bool	Fixed::operator<=(const Fixed& ref) const {
	return this->getRawBits() <= ref.getRawBits();
}

bool	Fixed::operator==(const Fixed& ref) const {
	return this->getRawBits() == ref.getRawBits();
}

bool	Fixed::operator!=(const Fixed& ref) const {
	return this->getRawBits() != ref.getRawBits();
}

Fixed	Fixed::operator+(Fixed const & ref) const {
	Fixed	ret(this->toFloat() + ref.toFloat());
	return ret;
}

Fixed	Fixed::operator-(Fixed const & ref) const {
	Fixed	ret(this->toFloat() - ref.toFloat());
	return ret;
}

Fixed	Fixed::operator*(Fixed const & ref) const {
	Fixed	ret(this->toFloat() * ref.toFloat());
	return ret;
}

Fixed	Fixed::operator/(Fixed const & ref) const {
	Fixed	ret(this->toFloat() / ref.toFloat());
	return ret;
}

Fixed&	Fixed::operator++(void) {
	this->value++;
	return *this;
}

const Fixed	Fixed::operator++(int) {
	const Fixed	old(*this);

	this->operator++();
	return old;
}

Fixed&	Fixed::operator--(void) {
	this->value--;
	return *this;
}

const Fixed	Fixed::operator--(int) {
	const Fixed	old(*this);

	this->operator--();
	return old;
}

Fixed&	Fixed::min(Fixed& ref1, Fixed& ref2) {
	if (ref1 <= ref2)
		return (ref1);
	return (ref2);
}

const Fixed&	Fixed::min(const Fixed& ref1, const Fixed& ref2) {
	if (ref1 <= ref2)
		return (ref1);
	return (ref2);
}

Fixed&	Fixed::max(Fixed& ref1, Fixed& ref2) {
	if (ref1 <= ref2)
		return (ref2);
	return (ref1);
}

const Fixed&	Fixed::max(const Fixed& ref1, const Fixed& ref2) {
	if (ref1 <= ref2)
		return (ref2);
	return (ref1);
}

std::ostream& operator<<(std::ostream& os, const Fixed& a)
{
	os << a.toFloat();
    return os;
}
