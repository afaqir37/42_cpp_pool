#ifndef _FIXED_HPP_
#define _FIXED_HPP_
#include <iostream>

class Fixed {
	private:
		int fixedPoint;
		static const int fracBits;
	public:
		Fixed() 
		{
			fixedPoint = 0;
		}
};

#endif