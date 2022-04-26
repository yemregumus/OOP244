/* Workshop #4 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-02-07
When I finish P1	: 2022-02-07
When I finish P2	: TBD      */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "CarInventory.h"




using namespace std;
using namespace sdds;
namespace sdds {


	CarInventory::CarInventory() {
		
		resetInfo();
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) 
	{

		if (type[0] == '\0' || brand[0] == '\0' || model[0] == '\0' || year <= 1989 || (code < 100 || code > 999) || price <= 0)
		{		
			resetInfo();
		}
		else
		{

			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];
			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);

			m_year = year;
			m_code = code;
			m_price = price;

		}
	}

	CarInventory::~CarInventory() {
		

		delete[] m_model;
		m_model = nullptr;


		delete[] m_brand;
		m_brand = nullptr;


		delete[] m_type;
		m_type = nullptr;
	
		

	}

	void CarInventory::resetInfo() {
		m_type = nullptr; 
		m_brand = nullptr; 
		m_model = nullptr; 
		m_year = 0; 
		m_code = 0; 
		m_price = 0;

	}


	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {

		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		
		m_type = new char[strlen(type) + 1];
		m_brand = new char[strlen(brand) + 1];
		m_model = new char[strlen(model) + 1];
		strcpy(m_type, type);
		strcpy(m_brand, brand);
		strcpy(m_model, model);

		m_year = year;
		m_code = code;
		m_price = price;

		return *this;

	}

	void CarInventory::printInfo() const {
		
		cout << "| ";
		cout.width(10);
		cout.setf(ios::left, ios::adjustfield);
		cout << m_type;
		cout.width(0);
		cout << " | ";
		cout.width(16);
		cout.setf(ios::left, ios::adjustfield);
		cout << m_brand;
		cout.width(0);
		cout << " | ";
		cout.width(16);
		cout.setf(ios::left, ios::adjustfield);
		cout << m_model;
		cout.width(0);
		cout << " | " << m_year << " |  " << m_code;
		cout << " |  ";
		cout.width(8);
		cout.setf(ios::right, ios::adjustfield);
		cout << fixed << setprecision(2) << m_price << " |" << endl;

	}


	bool CarInventory::isValid() const {

		bool returnValue = true;

		if (m_type == nullptr || m_brand == nullptr || m_model == nullptr || m_year <= 1989 || (m_code < 100 || m_code > 999) || m_price <= 0)
		{
			returnValue = false;
		}

		return returnValue;

	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const {


		bool returnValue = false;

		if (m_brand != nullptr && car.m_brand != nullptr)
		{
			if (m_type != nullptr && car.m_type != nullptr)
			{
				if (m_model != nullptr && car.m_model != nullptr)
				{
					if (m_year == car.m_year)
					{
						if (!strcmp(m_brand, car.m_brand) && !strcmp(m_type, car.m_type) && !strcmp(m_model, car.m_model))
						{
							returnValue = true;

						}
					}
				}		
			}			
		}
		
		return returnValue;
	}

	bool find_similar(const CarInventory car[], const int num_cars) {

		bool returnValue = false;

		for (int i = 0; i < num_cars; i++) {
			if (returnValue)
			{
				break;
			}
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					returnValue = true;
					break;
				}
			}
		}


		return returnValue;
	}
















}
