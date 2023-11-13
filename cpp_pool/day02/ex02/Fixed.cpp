#include "Fixed.hpp"

const int Fixed::fracBits = 8;

Fixed::Fixed()
{
	fixedPoint = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	fixedPoint = num << fracBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	fixedPoint = static_cast<int>(roundf(num * (1 << fracBits)));
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

float Fixed::toFloat(void) const 
{
	return static_cast<float>(fixedPoint) / (1 << fracBits);
}

int Fixed::toInt(void) const
{
	return fixedPoint / (1 << fracBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& t)
{
	os << t.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed& obj) const
{
	return this->fixedPoint > obj.fixedPoint;
}

bool Fixed::operator<(const Fixed& obj) const
{
	return this->fixedPoint < obj.fixedPoint;
}

bool Fixed::operator<=(const Fixed& obj) const
{
	return this->fixedPoint <= obj.fixedPoint;
}

bool Fixed::operator>=(const Fixed& obj) const
{
	return this->fixedPoint >= obj.fixedPoint;
}

bool Fixed::operator==(const Fixed &obj) const
{
	return this->fixedPoint == obj.fixedPoint;
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return this->fixedPoint != obj.fixedPoint;
}

Fixed Fixed::operator+(const Fixed& obj) const
{
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed& obj) const
{
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed& obj) const
{
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed & obj) const
{
	return Fixed(this->toFloat() / obj.toFloat());
}