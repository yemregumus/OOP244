/* Workshop #7 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-14
When I finish P1	: 2022-02-17
When I finish P2	: TBD*/

#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"

namespace sdds {


	class Pack : public Container
	{
	private:
		int p_unitSize{};
	
	public:
		Pack(const char* contentDesc, int size, int unitSize = 330, int numOfUnits = 0);
		~Pack();

		int operator +=(int addUnits);
		int operator -=(int removeUnits);
		int unit();
		int noOfUntis();
		int size();
		void clear(int packSize, int unitSize, const char* contentDesc);
		std::ostream& print(std::ostream& os);
		std::istream& read(std::istream& is);
	};

	std::ostream& operator << (std::ostream& ostr, Pack& pack);
	std::istream& operator >> (std::istream& istr, Pack& pack);









}
#endif // !SDDS_UTILS_H