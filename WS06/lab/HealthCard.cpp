

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "HealthCard.h"
using namespace std;
namespace sdds {

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
		set(name, number, vCode, sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc) {

		if (hc)	{
			allocateAndCopy(hc.m_name);
			strcpy(m_vCode, hc.m_vCode);
			strcpy(m_sNumber, hc.m_sNumber);
			m_number = hc.m_number;
		}
		else {
			setEmpty();
		}

	}

	HealthCard::~HealthCard() {
		delete[] m_name;
		m_name = nullptr;
	}
	
	void HealthCard::setEmpty()
	{
		delete[] m_name;
		m_name = nullptr;
		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';
	}

	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{
		bool returnValue = true;
		if (name == nullptr || strlen(name) == 0 || strlen(name) > MaxNameLength || (number <= 999999999 || number > 9999999999) || strlen(vCode) != 2 || strlen(sNumber) != 9)
		{
			returnValue = false;
		}

		return returnValue;
	}

	void HealthCard::allocateAndCopy(const char* name){
		
		if (name != nullptr || strlen(name))
		{
			delete[] m_name;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else
		{
			name = nullptr;
		}		
	}

	void HealthCard::extractChar(std::istream& istr, char ch) const {

		char nextChar;
		nextChar = istr.peek();

		if (nextChar == ch)
		{
			istr.ignore();
		}
		else
		{
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	std::ostream& HealthCard::printIDInfo(std::ostream& ostr) const
	{
		string strVal = to_string(m_number) + '-' + &m_vCode[0] + ", " + &m_sNumber[0];
		
		ostr << strVal;

		return ostr;

	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{

		if (validID(name, number, vCode, sNumber))
		{		
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);		
		}
		else
		{			
			setEmpty();
		}
	}

	istream& HealthCard::read(istream& istr) {
		//Luke Skywalker,1231231234-XL,AF1234567
		char l_name[MaxNameLength];
		long long l_number;
		char l_vCode[3];
		char l_sNumber[10];

		istr.get(l_name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> l_number;
		extractChar(istr, '-');
		istr.get(l_vCode, 3, ',');
		extractChar(istr, ',');
		istr.get(l_sNumber, 10, '\n');
		extractChar(istr, '\n');
		
		if (istr)
		{
			set(l_name, l_number, l_vCode, l_sNumber);
		}
		else
		{
			istr.clear();
			istr.ignore(1000, '\n');
		}

		istr.clear();
		return istr;
	}

	HealthCard::operator bool() const {
		
		bool returnValue = false;

		if (m_name != nullptr)
		{
			returnValue = true;
		}

		return returnValue;
	}

	std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const {

		if (validID(m_name, m_number, m_vCode, m_sNumber))
		{
			if (toFile)
			{
				ostr << m_name << ',';
				printIDInfo(ostr);
				ostr << endl;			
			}
			else
			{
				ostr.width(50);
				ostr.setf(ios::left, ios::adjustfield);
				ostr.fill('.');
				ostr << m_name;
				ostr.unsetf(ios::left);
				printIDInfo(ostr);			
			}
		}
		
		return ostr;
	}

	HealthCard& HealthCard::operator=(const HealthCard& hc) {

		if (this != &hc)
		{
			if (hc)
			{
				allocateAndCopy(hc.m_name);
				strcpy(m_vCode, hc.m_vCode);
				strcpy(m_sNumber, hc.m_sNumber);
				m_number = hc.m_number;
			}
			else
			{
				setEmpty();
			}
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc) {

		if (hc)
		{
			hc.print(ostr, false);
		}
		else
		{
			ostr << "Invalid Health Card Record";
		}

		return ostr;
	}

	std::istream& operator>>(std::istream& istr, HealthCard& hc) {

		return hc.read(istr);
	}

}
