#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
	private:
		int					value;
		const static int	bits = 8;
	public:
		Fixed();
		Fixed(int num);
		Fixed(const float num);
		Fixed(const Fixed &object);
		Fixed& operator=(const Fixed& object);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		int		toInt() const;
		float	toFloat() const;

		bool	operator>(Fixed const & ref) const;
		bool	operator<(Fixed const & ref) const;
		bool	operator>=(Fixed const & ref) const;
		bool	operator<=(Fixed const & ref) const;
		bool	operator==(Fixed const & ref) const;
		bool	operator!=(Fixed const & ref) const;

		Fixed	operator+(Fixed const & ref) const;
		Fixed	operator-(Fixed const & ref) const;
		Fixed	operator*(Fixed const & ref) const;
		Fixed	operator/(Fixed const & ref) const;

		Fixed&	operator++();
		const Fixed	operator++(int);
		Fixed&	operator--();
		const Fixed	operator--(int);

		static Fixed&	min(Fixed& ref1, Fixed& ref2);
		static const Fixed&	min(const Fixed& ref1, const Fixed& ref2);
		static Fixed&	max(Fixed& ref1, Fixed& ref2);
		static const Fixed&	max(const Fixed& ref1, const Fixed& ref2);
};

std::ostream &operator<<(std::ostream& os, const Fixed& object);

#endif  // FIXED_HPP
