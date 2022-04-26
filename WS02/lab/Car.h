#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "cStrTools.h"

namespace sdds {


	//Toyota C - HR, VYEEDG, 0001
	struct Car
	{
		char lincensePlate[9];
		char* makeAndModel;
		int showTime;

	};

	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);
	bool read(Car&);
	void print(const Car& C);
	void record(const Car& C);
	void endOfDay();
}
#endif