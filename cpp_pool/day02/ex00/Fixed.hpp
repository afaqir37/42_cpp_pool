#ifndef _FIXED_HPP_
#define _FIXED_HPP_
#include <iostream>

class Fixed {
	private:
		int fixedPoint;
		static const int fracBits;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator= (const Fixed& other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif