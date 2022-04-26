/* Workshop #8 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-21
When I finish P1	: 2022-03-22
When I finish P2	: TBD*/

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include <iostream>
#include "LblShape.h"
#include "Line.h"
#include "Utils.h"

namespace sdds {

	class Line : public LblShape
	{
	private:
		char m_length{};
	public:
		Line();
		Line(const char* labelOfLine, int lengthOfLine);

		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;


	};



}
#endif //!SDDS_LINE_H