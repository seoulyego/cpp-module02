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
};

std::ostream &operator<<(std::ostream& os, const Fixed& object);

#endif  // FIXED_HPP
