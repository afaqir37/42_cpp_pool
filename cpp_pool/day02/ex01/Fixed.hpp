#ifndef _FIXED_HPP_
#define _FIXED_HPP_
#include <iostream>
#include <cmatch>
class Fixed {
	private:
		int fixedPoint;
		static const int fracBits;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other);
		Fixed& operator= (const Fixed& other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFlat(void) const;
		int toInt(void) const;
};

#endif