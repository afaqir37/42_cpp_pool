#include "Fixed.hpp"

const int Fixed::fracBits = 8;

Fixed::Fixed()
{
	fixedPoint = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num)
{
	std::cout << "Default constructor called\n";
	fixedPoint = num << fracBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Default constructor called\n";
	fixedPoint = static_cast<int>(std::roundf(num * (1 << fracBits)));
}

Fixed::Fixed(const Fixed &other)
{
	fixedPoint = other.fixedPoint;
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		fixedPoint = other.fixedPoint;
	}
	std::cout << "Copy assignment operator called\n";
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	fixedPoint = raw;
}

float Fixed::toFlat(void) const 
{
	return static_cast<float>(fixedPoint) / (1 << fracBits);
}

int Fixed::toInt(void) const
{
	return fixedPoint / (1 << fracBits);
}