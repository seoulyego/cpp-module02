#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int					value;
		const static int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &object);
		Fixed& operator=(const Fixed& object);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif  // FIXED_HPP
