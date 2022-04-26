/* Workshop #8 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-21
When I finish P1	: 2022-03-22
When I finish P2	: TBD*/

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds {

	class Shape
	{
	public:
	
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;

		virtual ~Shape();

	};

	std::ostream& operator << (std::ostream& ostr, const Shape& st);
	std::istream& operator >> (std::istream& istr, Shape& specs);


}
#endif //!SDDS_SHAPE_H