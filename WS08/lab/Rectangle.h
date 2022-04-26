/* Workshop #7 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-14
When I finish P1	: 2022-02-17
When I finish P2	: TBD*/


#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include <iostream>
#include "LblShape.h"

namespace sdds {

	class Rectangle : public LblShape
	{
	private:
		unsigned char m_width{};
		unsigned char m_height{};
	public:
		
		Rectangle();
		Rectangle(const char* labelOfRect, unsigned char width, unsigned char height);
	
		void setEmpty();
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
		operator bool() const;
	};

	







}
#endif//!SDDS_RECTANGLE_H