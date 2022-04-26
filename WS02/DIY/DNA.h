/* Workshop #2 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC              */

#ifndef SDDS_DNA_H 
#define SDDS_DNA_H

namespace sdds {

	struct DnaRecord
	{
		int dnaID;
		char dnaStrand[1001];
	};


	bool beginSearch(const char* filename);
	bool read(const char* subDNA);
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();
	

}
#endif