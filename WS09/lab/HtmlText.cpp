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
#include "HtmlText.h"


namespace sdds {

	HtmlText::HtmlText()
	{
		m_title = nullptr;
	}

	HtmlText::HtmlText(const char* title)
	{
		ut.alocpy(m_title, title);
	}

	HtmlText::HtmlText(HtmlText& html)
	{
		ut.alocpy(m_title, html.m_title);

		(Text&)*this = html;
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	HtmlText& HtmlText::operator=(const HtmlText& html)
	{
		ut.alocpy(m_title, html.m_title);

		(Text&)*this = html;

		return *this;
	}

	std::ostream& HtmlText::write(std::ostream& os) const
	{

		bool MS = false;
		char lessThan[] = "&lt;";
		char greaterThan[] = "&gt;";
		char newLine[] = "<br />\n";
		char space[] = "&nbsp;";
		char incomingChar = 0;
		int index = 0;


		os << "<html><head><title>";

		if (m_title)
		{
			os << m_title;
			
		}
		else
		{
			os << "No Title";
		}

		os << "</title></head>\n<body>\n";

		if (m_title)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}
		
		do
		{
			incomingChar = Text::operator[](index);
	
			switch (incomingChar)
			{
			case '\0':
				break;
			case ' ':
				if (MS == true)
				{
					os << space;

				}
				else
				{
					MS = true;
					os << ' ';
				}
				break;
			case '<':
				os << lessThan;
				MS = false;
				break;
			case '>':
				os << greaterThan;
				MS = false;
				break;
			case '\n':
				os << newLine;
				MS = false;
				break;

			default:
				os << incomingChar;
				MS = false;
				break;
			}

			index++;
		} while (incomingChar);

		os << "</body>\n</html>";

		return os;
	}

	std::ostream& operator<<(std::ostream& os, const HtmlText& html)
	{
		html.write(os);

		return os;
	}

	std::istream& operator>>(std::istream& is, HtmlText& html)
	{

		html.read(is);

		return is;
	}

}
