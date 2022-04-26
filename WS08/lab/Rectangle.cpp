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
#include "Rectangle.h"


namespace sdds {


	Rectangle::Rectangle() : LblShape()
	{
		m_height = 0;
		m_width = 0;
	}

	Rectangle::Rectangle(const char* labelOfRect, unsigned char width, unsigned char height) : LblShape(labelOfRect)
	{
		m_height = height;
		m_width = width;

		if (m_height < 3 || m_width < (strlen(label() + 2)))
		{
			setEmpty();
		}
	}

	void Rectangle::getSpecs(std::istream& is)
	{
		int tempWidth = 0, tempHeigth = 0;
		LblShape::getSpecs(is);

		is >> tempWidth;
		is.ignore();
		is >> tempHeigth;
		is.ignore(1000, '\n');

		m_width = tempWidth;
		m_height = tempHeigth;

	}

	void Rectangle::draw(std::ostream& os) const
	{
		if (*this)
		{
			os << '+';
			os.fill('-');
			os.width(m_width - 1);
			os << '+' << '\n';

			os << '|';
			os.fill(' ');
			os.width(m_width - 2);
			os.setf(std::ios::left, std::ios::adjustfield);
			os << label();
			os << '|' << '\n';

			for (int i = 0; i < (m_height -3); i++)
			{
				os << '|';
				os.fill(' ');
				os.width(m_width - 1);
				os.setf(std::ios::right, std::ios::adjustfield);
				os << '|' << '\n';
			}

			os << '+';
			os.fill('-');
			os.width(m_width - 1);
			os << '+';

		}
	}

	void Rectangle::setEmpty()
	{
		m_height = 0;
		m_width = 0;

		emptyLabel();
	}

	Rectangle::operator bool() const 
	{
		return (m_height > 0 && m_width > 0);
	}

}