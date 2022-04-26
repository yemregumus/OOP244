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
#include <cstring>
#include "Utils.h"


#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
namespace sdds {

	class Text
	{
	private:
		char* m_content{};
	protected:
		const char& operator[](int index)const;
	public:
		Text();
		Text(Text& txt);
		~Text();

		Text& operator =(const Text& txt);

		std::istream& read(std::istream& is);
		virtual std::ostream& write(std::ostream& os) const;

	};

	std::ostream& operator <<(std::ostream& os, const Text& txt);
	std::istream& operator >>(std::istream& is, Text& txt);


}

#endif // !SDDS_TEXT_H