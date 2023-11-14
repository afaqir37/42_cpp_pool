#ifndef _FIXED_HPP_
#define _FIXED_HPP_
#include <iostream>
#include <cmath>
class Fixed
{
private:
	int fixedPoint;
	static const int fracBits;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	
	bool operator>(const Fixed& obj) const;
	bool operator<(const Fixed& obj) const;
	bool operator<=(const Fixed& obj) const;
	bool operator>=(const Fixed& obj) const;
	bool operator==(const Fixed& obj) const;
	bool operator!=(const Fixed& obj) const;

	Fixed operator+(const Fixed& obj) const;
	Fixed operator-(const Fixed& obj) const;
	Fixed operator*(const Fixed& obj) const;
	Fixed operator/(const Fixed& obj) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);


};
std::ostream &operator<<(std::ostream &os, const Fixed &t);

#endif