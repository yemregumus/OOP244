/* Workshop #8 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-21
When I finish P1	: 2022-03-22
When I finish P2	: TBD*/


#include <iostream>
#include "LblShape.h"
#include "Utils.h"
#include "Line.h"


namespace sdds {
	Line::Line() : LblShape()
	{
		m_length = 0;
	}

	Line::Line(const char* labelOfLine, int lengthOfLine) : LblShape(labelOfLine)
	{
		m_length = lengthOfLine;
	}

	void Line::getSpecs(std::istream& is)
	{
		int temp = 0;
		LblShape::getSpecs(is);

		is >> temp;
		is.ignore(1000, '\n');

		m_length = temp;
	}

	void Line::draw(std::ostream& os) const
	{
		if (m_length > 0 && label() != nullptr)
		{
			os << label() << '\n';

			for (int i = 0; i < m_length; i++) {
				os << '=';
			}
		}
	}

}