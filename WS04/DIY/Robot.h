/* Workshop #4 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-02-07
When I finish P1	: 2022-02-07
When I finish P2	: 2022-02-08*/

#ifndef SDDS_ROBOT__H 
#define SDDS_ROBOT__H

namespace sdds {

	class Robot
	{
	
		char* r_name;
		char* r_location;
		double r_weight;
		double r_width;
		double r_height;
		double r_speed;
		bool r_deployed;

		void resetRobot();

	public:
		Robot();
		Robot(const char* robot_name, const char* robot_location, double robot_weight, double robot_width, double robot_height, double robot_speed, bool robot_deployment);
		~Robot();


		Robot& set(const char* robot_name, const char* robot_location, double robot_weight, double robot_width, double robot_height, double robot_speed, bool robot_deployment);
		void setLocation(const char* robot_location);
		void setDeployed(bool robot_deployment);
		char* getName()const;
		char* getLocation()const;
		bool isDeployed()const;
		bool isValid ()const;
		double speed()const;
		void display()const;
	
	};
	
	void cRHeader();
	int conrtolRooomReport(const Robot robots[], int num_robots);
	
}
#endif