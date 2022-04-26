/* Workshop #8 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-21
When I finish P1	: 2022-03-22
When I finish P2	: TBD*/

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <iostream>


#include "Shape.h"

namespace sdds {

	class LblShape : public Shape
	{
	private:
		char* m_label{};
	protected:
		const char* label() const;
		void emptyLabel();
	public:
		LblShape();
		LblShape(char const* label);
		LblShape(const LblShape&) = delete;
		
		virtual ~LblShape();
		void getSpecs(std::istream& is);
		virtual void draw(std::ostream& os) const;
		
		LblShape& operator =(const LblShape&) = delete;
		

	
	};









}
#endif //!SDDS_LBLSHAPE_H