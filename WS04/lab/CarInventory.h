/* Workshop #4 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-02-07
When I finish P1	: 2022-02-07
When I finish P2	: TBD      */


#ifndef SDDS_CARINVENTORY_H 
#define SDDS_CARINVENTORY_H

namespace sdds {

	class CarInventory {

	private:		
		char* m_type; //not null
		char* m_brand; //not null
		char* m_model; //not null
		int m_year; //>= 1990
		int m_code; //three digit integer
		double m_price; // > 0

		
		void resetInfo();


	public:
		
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		~CarInventory(); 
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;		

	};

	bool find_similar(const CarInventory car[], const int num_cars);


}
#endif