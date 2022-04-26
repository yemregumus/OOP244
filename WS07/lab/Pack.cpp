/* Workshop #7 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-14
When I finish P1	: 2022-02-17
When I finish P2	: TBD*/

#include <iostream>
#include "Pack.h"
#include "Utils.h"
using namespace std;

namespace sdds {

	Pack::Pack(const char* contentDesc, int size, int unitSize, int numOfUnits) : Container(contentDesc, (unitSize * size), (unitSize * numOfUnits))
	{
		if (unitSize > 0 && numOfUnits <= size)
		{
			p_unitSize = unitSize;
		}
		else
		{
			setEmpty();
			p_unitSize = 0;
		}
	}

	Pack::~Pack()
	{
		setEmpty();
	}

	int Pack::operator+=(int addUnits)
	{
		int value = Container::operator+=(addUnits * p_unitSize);

		return value / p_unitSize;
	}

	int Pack::operator-=(int removeUnits)
	{
		int value = Container::operator-=(removeUnits * p_unitSize);

		return value / p_unitSize;
	}

	int Pack::unit()
	{
		return p_unitSize;
	}

	int Pack::noOfUntis()
	{
		int returnValue = volume();

		return returnValue / p_unitSize;
	}

	int Pack::size()
	{
		int returnValue = capacity();

		return returnValue / p_unitSize;
	}

	void Pack::clear(int packSize, int unitSize, const char* contentDesc)
	{
		if (unitSize > 0)
		{
			Container::clear(packSize * unitSize, contentDesc);
			p_unitSize = unitSize;
		}
	}

	std::ostream& Pack::print(std::ostream& os)
	{
		int packSize = 0, numOfUnits = 0;

		

		
		Container::print(os);
	
		if (p_unitSize > 0)
		{
			packSize = size();
			numOfUnits = noOfUntis();
			//", XX in a pack of YY"
			os << ", " << numOfUnits << " in a pack of " << packSize;
		}

		return os;
	}

	std::istream& Pack::read(std::istream& is)
	{
		int packSize = 0, numOfUnits = 0;

		

		if (p_unitSize > 0) {
			packSize = size();
			numOfUnits = noOfUntis();

			if (numOfUnits < packSize)
			{		
				std::cout << "Add to ";
				print(std::cout);
				int value = ut.getint(1, (packSize - numOfUnits), "> ");
				*this += value;
				std::cout << "Added " << value << endl;
			}
			else
			{
				char enter[10];

				is.clear();
				std::cout << "Pack is full!, press <ENTER> to continue...";
				is.clear();
				is.ignore(1000, '\n');
				is.get(enter, 10);
				Container::read(is);

		
			}
		}

		return is;
	}

	std::ostream& operator <<(std::ostream& ostr, Pack& pack)
	{
		pack.print(ostr);

		return ostr;
	}

	std::istream& operator >>(std::istream& istr, Pack& pack)
	{
		pack.read(istr);

		return istr;
	}

}