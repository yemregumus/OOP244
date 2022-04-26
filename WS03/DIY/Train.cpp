/* Workshop #3 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-02-02
When I finish P1	: 2022-02-02
When I finish P2	: 2022-02-02      */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Train.h"



using namespace std;
namespace sdds {


	void Train::set(const char* trainName_, int numberOfPeople_, double trainSpeed_) {
		
		bool valid = true;
		

		if (trainName_ == nullptr || strlen(trainName_) <= 0)
		{
			valid = false;
		}
		if (numberOfPeople_ <= 0 || numberOfPeople_ > MAX_PEOPLE)
		{
			valid = false;
		}
		if (trainSpeed_ <= 0 || trainSpeed_ > MAX_SPEED)
		{
			valid = false;
		}

		if (valid)
		{
			strncpy(trainName, trainName_, MAX_NAME_LEN);
			numberOfPeople = numberOfPeople_;
			trainSpeed = trainSpeed_;
		}
		else
		{
			//setting trainName  to empty state with setting first element to string terminator.
			trainName[0] = '\0';
			//setting numberOfPeople to 0 for setting it to safe empty state by ignoring the incoming data.
			numberOfPeople = 0;
			//setting trainSpeed to 0 for setting it to safe empty state by ignoring the incoming data.
			trainSpeed = 0; 
		}
	}



	int Train::getNumberOfPeople() const {
		
		return numberOfPeople;
	}

	const char* Train::getName() const {
		
		return trainName;
	}

	double Train::getSpeed() const {
		
		return trainSpeed;
	}

	bool Train::isSafeEmpty() const {
		
		bool returnValue = false;

		if (trainName[0] == '\0')
		{
			returnValue = true;
		}

		return returnValue;
	}
	
	void Train::display() const {
	
		if (isSafeEmpty())
		{
			cout << "Safe Empty State!" << endl;
		}
		else 
		{
		cout << "NAME OF THE TRAIN : " << trainName << endl;
		cout << "NUMBER OF PEOPLE  : " << numberOfPeople << endl;
		cout << "SPEED             : " << fixed << showpoint << setprecision(2) << trainSpeed << " km/h" << endl;
		}
	}
	
	bool Train::loadPeople(int peopleAmount)
	{
		bool returnValue = true;
		if (isSafeEmpty())
		{
			returnValue = false;
		}
		else
		{
			numberOfPeople += peopleAmount;
			if (numberOfPeople < 0)
			{
				numberOfPeople = 0;
			}
			else if (numberOfPeople > MAX_PEOPLE)
			{
				numberOfPeople = MAX_PEOPLE;
			}

		}

		return returnValue;
	}
	
	bool Train::changeSpeed(int speedChange)
	{
		bool returnValue = true;
		if (isSafeEmpty())
		{
			returnValue = false;
		}
		else
		{
			trainSpeed += speedChange;
			if (trainSpeed < 0)
			{
				trainSpeed = 0;
			}
			else if (trainSpeed > MAX_SPEED)
			{
				trainSpeed = MAX_SPEED;
			}

		}

		return returnValue;

	}
	
	int transfer(Train& r_receivingTrain, Train& r_transferringTrain)
	{

		int returnValue = -1;
		if (r_receivingTrain.isSafeEmpty() || r_transferringTrain.isSafeEmpty())
		{
			returnValue = -1;
		}
		else
		{									
		int tPeople = r_transferringTrain.getNumberOfPeople();
		int rPeople = r_receivingTrain.getNumberOfPeople(); 


		int maxCapacity = MAX_PEOPLE - rPeople;

		if (maxCapacity >= tPeople)
		{
			maxCapacity = tPeople;
		}

		r_transferringTrain.loadPeople(-maxCapacity);

		r_receivingTrain.loadPeople(maxCapacity);

		returnValue = maxCapacity;
		}

		return returnValue;
		
	}
	
}