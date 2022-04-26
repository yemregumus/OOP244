/* Workshop #8 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-21
When I finish P1	: 2022-03-22
When I finish P2	: TBD*/


#include "Shape.h"

namespace sdds {

	std::ostream& operator<<(std::ostream& ostr, const Shape& st)
	{
		st.draw(ostr);

		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Shape& specs)
	{
		specs.getSpecs(istr);

		return istr;
	}
	Shape::~Shape()
	{
	}
}