/* Workshop #9 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-28
When I finish P1	: 2022-03-29
When I finish P2	: TBD*/


#include <iostream>
#include "Text.h"
#include "Utils.h"

#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
namespace sdds {

	class HtmlText : public Text
	{
	private:
		char* m_title{};

	public:
		HtmlText();
		HtmlText(const char* title);
		HtmlText(HtmlText& html);
		~HtmlText();

		HtmlText& operator =(const HtmlText& html);

		std::ostream& write(std::ostream& os) const;

	};
	std::ostream& operator <<(std::ostream& os, const HtmlText& html);
	std::istream& operator >>(std::istream& is, HtmlText& html);











}

#endif // !SDDS_HTMLTEXT_H