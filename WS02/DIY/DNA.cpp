/* Workshop #2 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC              */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "cStrTools.h"
#include "DNA.h"


using namespace std;
namespace sdds {

	ifstream ifs;
	int arraySize = 50;
	int arrayCount = 0;
	DnaRecord* dnaArray;

	bool beginSearch(const char* filename) {

		bool returnValue = false;

		ifs.open(filename, ios::in);

		if (ifs.is_open()){
			returnValue = true;
		}
		
		cout << "DNA search program" << endl;

		return returnValue;
	}

	bool read(const char* subDNA) {
		


		bool returnValue = false;
		string dnaID;
		string dnaStrand;
		string readLine;
		unsigned int returned;

		arrayCount = 0;
		arraySize = 50;
		

		dnaArray = new DnaRecord[arraySize];

		
		while (getline(ifs, readLine))
		{
			

			returned = readLine.find(subDNA);
			if (returned > 6 && returned < readLine.length())
			{
				if (arrayCount >= arraySize)
				{
					arraySize = arraySize + 10;

					DnaRecord* localDnaPtr = new DnaRecord[arraySize];

					for (int i = 0; i < arrayCount; i++)
					{
						localDnaPtr[i] = dnaArray[i];
					}
					delete[] dnaArray;
					dnaArray = nullptr;
					dnaArray = localDnaPtr;
				
				}
			
				returnValue = true;
				
				
				dnaID = readLine.substr(0, 6);
				dnaStrand = readLine.substr(7, readLine.length() - 1);

				dnaArray[arrayCount].dnaID = stoi(dnaID);
				strCpy(dnaArray[arrayCount].dnaStrand, &dnaStrand[0]);
				arrayCount += 1;
					
			}
		}

		ifs.clear();
		ifs.seekg(0, ios::beg);

		

		return returnValue;
	}

	void sort() 
	{
		int idBuffer = 0;
		char strandBuffer[1001];

		for (int i = 0; i < arrayCount; i++)
		{	
			for (int j = i; j < arrayCount; j++)
			{
				if (dnaArray[i].dnaID > dnaArray[j].dnaID)
				{
					idBuffer = dnaArray[i].dnaID;
					strCpy(strandBuffer, dnaArray[i].dnaStrand);
					dnaArray[i].dnaID = dnaArray[j].dnaID;
					strCpy(dnaArray[i].dnaStrand, dnaArray[j].dnaStrand);
					strCpy(dnaArray[j].dnaStrand, strandBuffer);
					dnaArray[j].dnaID = idBuffer;
				}
			}
		}	
	}

	void displayMatches() {
		
		cout << arrayCount << " matches found:" << endl;

		for (int i = 0; i < arrayCount; i++)
		{
			if (dnaArray[i].dnaID > 0) 
			{
				cout << i + 1 << ") " << dnaArray[i].dnaID << ":" << endl;
				cout << dnaArray[i].dnaStrand << endl;
				cout << "======================================================================" << endl;
			}
		}
	}

	void deallocate() {
		delete[] dnaArray;
		dnaArray = nullptr;
	}

	void endSearch() {
		deallocate();
		ifs.close();
		cout << "DNA Search Program Closed." << endl;
	}

}