/* Workshop #4 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-02-07
When I finish P1	: 2022-02-07
When I finish P2	: 2022-02-08*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Robot.h"


using namespace std;
using namespace sdds;

namespace sdds {

	Robot::Robot() {

		resetRobot();
	}
	
	Robot::Robot(const char* robot_name, const char* robot_location, double robot_weight, double robot_width, double robot_height, double robot_speed, bool robot_deployment) {

		resetRobot();
		set(robot_name, robot_location, robot_weight, robot_width, robot_height, robot_speed, robot_deployment);
	}
	
	Robot::~Robot() {

		delete[] r_name;
		r_name = nullptr;
		delete[] r_location;
		r_location = nullptr;
	}
	

	Robot& Robot::set(const char* robot_name, const char* robot_location, double robot_weight, double robot_width, double robot_height, double robot_speed, bool robot_deployment) {
		

		if (robot_name == nullptr || robot_location == nullptr || robot_weight <= 0 || robot_width <= 0 || robot_height <= 0 || robot_speed <= 0) {

			resetRobot();
		}
		else
		{

			
			if (r_name != nullptr)
			{

				delete[] r_name;
			}
			if (r_location != nullptr)
			{
	
				delete[] r_location;
			}

			r_name = new char[strlen(robot_name) + 1];
			r_location = new char[strlen(robot_location) + 1];

			strcpy(r_name, robot_name);
	
			strcpy(r_location, robot_location);

			r_weight = robot_weight;
			r_width = robot_width;
			r_height = robot_height;
			r_speed = robot_speed;
			r_deployed = robot_deployment;
		}

		return *this;
	}
	
	void Robot::setLocation(const char* robot_location) {
		
		delete[] r_location;	
		
		r_location = new char[strlen(robot_location) + 1];

		strcpy(r_location, robot_location);

	}
	
	void Robot::setDeployed(bool robot_deployment) {

		r_deployed = robot_deployment;

	}

	char* Robot::getName() const {

		return r_name;

	}
	
	char* Robot::getLocation() const {

		return r_location;
	}
	
	bool Robot::isDeployed() const {

		return r_deployed;
	}
	
	bool Robot::isValid() const {

		bool returnValue = true;

		if (r_name == nullptr || r_location == nullptr || r_weight <= 0 || r_width <= 0 || r_height <= 0 || r_speed < 0)
		{
			returnValue = false;
		}

		return returnValue;
	}
	
	double Robot::speed()const {

		return r_speed;
	}

	
	void Robot::display() const {


		cout << "| ";
		cout.width(10);
		cout.setf(ios::left, ios::adjustfield);
		cout << r_name;
		cout.width(0);
		cout << " | ";
		cout.width(15);
		cout.setf(ios::left, ios::adjustfield);
		cout << r_location;
		cout.width(0);
		cout << " | ";
		cout.width(6);
		cout.setf(ios::left, ios::adjustfield);
		cout << fixed << setprecision(1) << r_weight;
		cout.width(0);
		cout << " | ";
		cout.width(6);
		cout.setf(ios::left, ios::adjustfield);
		cout << fixed << setprecision(1) << r_width;
		cout.width(0);
		cout << " | ";
		cout.width(6);
		cout.setf(ios::left, ios::adjustfield);
		cout << fixed << setprecision(1) << r_height;
		cout.width(0);
		cout << " | ";
		cout.width(6);
		cout.setf(ios::left, ios::adjustfield);
		cout << fixed << setprecision(1) << r_speed;
		cout << " | ";
		cout.width(8);
		cout.setf(ios::left, ios::adjustfield);
		if(r_deployed){
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout.width(0);
		cout << " |" << endl;
	}

	void Robot::resetRobot() {		
		
		r_name = nullptr;
		r_location = nullptr;;
		r_weight = 0.0;
		r_width = 0.0;
		r_height = 0.0;
		r_speed = 0.0;
		r_deployed = false;

	}
	


	void cRHeader() {

		cout.width(55);
		cout.setf(ios::right, ios::adjustfield);
		cout << "------ Robot Control Room -----" << endl;
		cout.width(59);
		cout.setf(ios::right, ios::adjustfield); 
		cout << "---------------------------------------" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
	}

	int conrtolRooomReport(const Robot robots[], int num_robots) {

		int returnValue = -1;
		float maxSpeed = 0.0;
		int maxSpeedIndex = 0;
		int i = 0, j = 0;

		cRHeader();

		for (i = 0; i < num_robots; i++)
		{

			if (robots[i].isValid())
			{
				robots[i].display();
				if (robots[i].speed() > maxSpeed)
				{
					maxSpeed = robots[i].speed();
					maxSpeedIndex = i;
				}
				if (robots[i].isDeployed())
				{
					j++;
				}
			}
			else
			{
				returnValue = i;
				break;
			}

		}


		if (returnValue == -1)
		{
			cout << "|=============================================================================|" << endl;			
			cout << "| SUMMARY:                                                                    |" << endl;
			cout << "| " << j << " robots are deployed.                                                      |" << endl;
			cout << "| The fastest robot is:                                                       |" << endl;
			cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
			cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
			robots[maxSpeedIndex].display();
			cout << "|=============================================================================|" << endl;
			

		}



		return returnValue;
	}



}


