/* Workshop #9 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-28
When I finish P1	: 2022-03-29
When I finish P2	: TBD*/

#include <iostream>
#include <fstream>
#include "Text.h"
#include "Utils.h"


namespace sdds {
	
	Text::Text()
	{
		m_content = nullptr;
	}

	Text::Text(Text& txt)
	{
		ut.alocpy(m_content, txt.m_content);
	}

	Text::~Text()
	{
		delete[] m_content;
		m_content = nullptr;	
	}

	Text& Text::operator=(const Text& txt)
	{
		ut.alocpy(m_content, txt.m_content);

		return *this;
	}

	std::istream& Text::read(std::istream& is)
	{

		int lenght = 0;
		delete[] m_content;
		m_content = nullptr;

		lenght = ut.getFileLength(is);


		m_content = new char[lenght + 1];
		is.get(m_content, lenght + 1, EOF);

		if (m_content)
		{
			is.clear();
		}

		return is;
	}

	std::ostream& Text::write(std::ostream& os) const
	{
		if (m_content)
		{
			os << m_content;
		}

		return os;
	}


	const char& Text::operator[](int index) const
	{
		return m_content[index];
	}


	std::ostream& operator<<(std::ostream& os, const Text& txt)
	{
		txt.write(os);

		return os;
	}

	std::istream& operator>>(std::istream& is, Text& txt)
	{

		txt.read(is);

		return is;
	}


}
