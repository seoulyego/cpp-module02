#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
	private:
		int					value;
		const static int	bits = 8;
	public:
		Fixed(void);
		Fixed(int num);
		Fixed(const float num);
		Fixed(const Fixed &object);
		Fixed& operator=(const Fixed& object);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(Fixed const & ref) const ;
		bool	operator<(Fixed const & ref) const ;
		bool	operator>=(Fixed const & ref) const ;
		bool	operator<=(Fixed const & ref) const ;
		bool	operator==(Fixed const & ref) const ;
		bool	operator!=(Fixed const & ref) const ;

		Fixed	operator+(Fixed const & ref) const ;
		Fixed	operator-(Fixed const & ref) const ;
		Fixed	operator*(Fixed const & ref) const ;
		Fixed	operator/(Fixed const & ref) const ;
};

std::ostream &operator<<(std::ostream& , const Fixed& );

#endif  // FIXED_HPP