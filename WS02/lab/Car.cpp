/* Workshop #2 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC              */

#include <iostream>
#include "Car.h"
#include "cStrTools.h"

using namespace std;
using namespace sdds;

namespace sdds {

	Car* carPtr;
	int allocationSize;
	int numberOfCars;
	int carArraySize;

	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry" << '\n'
			<< "Enter the data in the following format:" << '\n'
			<< "Make and model,LicensePlate,MilitaryTime<ENTER>" << '\n'
			<< "Exit the program by entering the following:" << '\n'
			<< "X,<ENTER>" << '\n' << endl;

	}
	void initialize(int allocSize)
	{
		numberOfCars = 0;
		carArraySize = allocSize;
		allocationSize = allocSize;
		carPtr = new Car[allocSize];
	}

	void deallocate(Car& C) {

		delete [] C.makeAndModel;
		C.makeAndModel = nullptr;
	}

	bool read(Car& C) {
		
		bool flag = false;
		char makeAndModel[61];
		

		read(makeAndModel, 60, ',');
		
		if (makeAndModel[0] != 'X' && strLen(makeAndModel) > 2)
		{
			flag = true;
			C.makeAndModel = new char[61];
			strCpy(C.makeAndModel, makeAndModel);
			read(C.lincensePlate, 8, ',');
			cin >> C.showTime;	
		}

		return flag;
	}

	void print(const Car& C) {

		cout << C.showTime << ": " << C.makeAndModel << ", " << C.lincensePlate << endl;
	}

	void record(const Car& C) {
		if (numberOfCars == carArraySize)
		{
			allocationSize = numberOfCars + carArraySize;
			
			Car* localCarPtr = new Car[allocationSize];

			for (int i = 0; i < numberOfCars; i++)
			{	
				localCarPtr[i] = carPtr[i];
			}
			
			delete[] carPtr;
			carPtr = nullptr;
			carPtr = localCarPtr;

			carArraySize = allocationSize;
		}
		carPtr[numberOfCars] = C;
		numberOfCars += 1;
	}


void endOfDay() {

	for (int i = 0; i < numberOfCars; i++)
	{
		print(carPtr[i]);
		deallocate(carPtr[i]);
	}
	delete[] carPtr;
	carPtr = nullptr;
}

}