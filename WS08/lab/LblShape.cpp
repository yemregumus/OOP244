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

namespace sdds {

	const char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape()
	{
		m_label = nullptr;
	}

	LblShape::LblShape(char const* label)
	{
		ut.alocpy(m_label, label);
	}

	LblShape::~LblShape()
	{
		emptyLabel();
	}

	void LblShape::getSpecs(std::istream& is)
	{
		char* temp = new char[100];

		is.getline(temp, 100, ',');


		ut.alocpy(m_label, temp);

		delete[] temp;
	}

	void LblShape::draw(std::ostream& os) const
	{
	}

	void LblShape::emptyLabel() {
		delete[] m_label;
		m_label = nullptr;
	}
}