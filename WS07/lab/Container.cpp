/* Workshop #7 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-14
When I finish P1	: 2022-02-17
When I finish P2	: TBD*/

#include <iostream>
#include <cstring>
#include "Container.h"
#include "Utils.h"


namespace sdds {
	Container::Container()
	{
		setEmpty();
	}
	Container::Container(const char* content, int capacity, int contentVolume)
	{
		if (content != nullptr && strlen(content) > 0 && contentVolume < capacity)
		{
			c_maxCapacityOfCC = capacity;
			c_contentVolume = contentVolume;

			if (strlen(content) < MAX_CONTENTDESC_CHAR)
			{
				ut.alocpy(c_contentDesc, content);
			}
			else
			{
				ut.alocpy(c_contentDesc, content, MAX_CONTENTDESC_CHAR);
			}
		}
		else
		{
			setEmpty();
		}
		
	}

	Container::~Container()
	{
		setEmpty();
	}

	void Container::setEmpty()
	{
		delete[] c_contentDesc;
		c_contentDesc = nullptr;
		c_maxCapacityOfCC = 0;
		c_contentVolume = 0;
	}

	int Container::capacity()
	{
		return c_maxCapacityOfCC;
	}

	int Container::volume()
	{
		return c_contentVolume;
	}
	

	int Container::operator+=(int addValue)
	{
		//volume = 100 maxcapacity = 200 addValue = 50
		//volume = 100 maxcapacity = 200 addValue = 150
		int addable = c_maxCapacityOfCC - c_contentVolume;

		if (addable >= addValue)
		{
			c_contentVolume += addValue;
			addable = addValue;
		}
		else
		{
			c_contentVolume += addable;
		}

		return addable;
	}

	int Container::operator-=(int deductValue)
	{
		//volume = 100 maxcapacity = 200 deductValue = 50
		//volume = 100 maxcapacity = 200 deductValue = 150
		int deductable = c_contentVolume;

		if (deductable >= deductValue)
		{
			c_contentVolume -= deductValue;
			deductable = deductValue;
		}
		else
		{
			c_contentVolume = 0;
		}

		return deductable;
	}

	Container::operator bool() const
	{
		return (c_contentDesc != nullptr && c_contentVolume <= c_maxCapacityOfCC);
	}

	void Container::clear(int capacity, const char* contentDesc)
	{
		if (capacity > 0 && contentDesc != nullptr)
		{
			if (strlen(contentDesc) < MAX_CONTENTDESC_CHAR)
			{
				ut.alocpy(c_contentDesc, contentDesc);
			}
			else
			{
				ut.alocpy(c_contentDesc, contentDesc, MAX_CONTENTDESC_CHAR);
			}
			c_maxCapacityOfCC = capacity;
		}
	}

	std::ostream& Container::print(std::ostream& os) const
	{
		if (*this)
		{
			os << c_contentDesc << ": (" << c_contentVolume << "cc/" << c_maxCapacityOfCC << ')';
		}
		else
		{
			os << "****: (**cc/***)";
		}

		return os;
	}

	std::istream& Container::read(std::istream& is)
	{
		if (*this)
		{
			if (c_contentVolume >= c_maxCapacityOfCC)
			{
				
				std::cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
				is.clear();
				is.ignore(1000, '\n');

				is.clear();
				is.ignore(1000, '\n');
			}
			else
			{
				std::cout << "Add to ";
				print(std::cout);
				int intValue = ut.getint(1, 220000, "> ");
				std::cout << "Added " << (*this += intValue) << " CCs" << std::endl;
			}			
		}
		else
		{
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			is.clear();
			is.ignore(1000, '\n');
			is.clear();
			is.ignore(1000, '\n');
		}


		return is;
	}

	std::ostream& operator<<(std::ostream& ostr, const Container& container)
	{
		container.print(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Container& container)
	{
		container.read(istr);

		return istr;
	}

}