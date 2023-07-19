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

std::ostream& operator<<(std::ostream& os, const Fixed& a)
{
	os << a.toFloat();
    return os;
}
