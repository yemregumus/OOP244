/* Workshop #3 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-02-02
When I finish P1	: 2022-02-02
When I finish P2	: 2022-02-02      */


#define MAX_NAME_LEN 20
#define MAX_PEOPLE 1000
#define MAX_SPEED 320

#ifndef SDDS_TRAIN_H 
#define SDDS_TRAIN_H

namespace sdds {

	class Train {

	private:
		char trainName[MAX_NAME_LEN];
		int numberOfPeople;
		double trainSpeed;

	public:
		void set(const char* trainName_, int numberOfPeople_, double trainSpeed_);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
		bool loadPeople(int peopleAmount);
		bool changeSpeed(int speedChange);

	};
	int transfer(Train &r_receivingTrain, Train &r_transferringTrain);

}
#endif