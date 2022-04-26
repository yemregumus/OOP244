/* Workshop #1 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC              */


/* ------------------------------------------------------
Workshop 1 part 2
Module: directory
Filename: directory.cpp
Version 1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#include "Phone.h"
#include <iostream>
#include <fstream>
using namespace sdds;
int main() {
	phoneDir("Star Wars", "phones.txt");
	std::cout << std::endl << "----------------------------------" << std::endl;
	phoneDir("Star Wars", "badDataFile.txt");
	
	return 0;
}