/* Workshop #1 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC              */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <fstream>
#include "Phone.h"
#include "cStrTools.h"


using namespace std;

namespace sdds {

	void headTitle(const char* programTitle) {

		cout << programTitle << " phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;

	}

	void readAndFind(const char* fileName) {
		
		int flag = 1;
		char partialName[25];
		char lowerPartialName[25];
		char nameInList[33];
		char lowerNameInList[33];
		char areaNo[10];
		char prefixNo[10];
		char phoneNo[10];
		const char* nameFound = nullptr;



		ifstream ifs(fileName);
		if (ifs.is_open()) {

		
		while (flag)
		{

			cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
			cout << "> ";
			cin >> partialName;
			if (partialName[0] == '!') {
				flag = 0;
			}
			else
			{
				

				FILE* fp = fopen(fileName, "r");
				
				
					trim(partialName);
					toLowerCaseAndCopy(lowerPartialName, partialName);

					do
					{
						fscanf(fp, "%[^\t]\t%s\t%s\t%s\n", nameInList, areaNo, prefixNo, phoneNo);


						toLowerCaseAndCopy(lowerNameInList, nameInList);

						nameFound = strStr(lowerNameInList, lowerPartialName);

						if (nameFound != nullptr)
						{
							cout << nameInList << ": " << "(" << areaNo << ")" << " " << prefixNo << "-" << phoneNo << endl;
						}

					} while (!feof(fp));	
				
					
				fclose(fp);


				
			}
		}
		}
		else {
			// show message:
			std::cout << fileName << " file not found!" << endl;
		}
	}

	void phoneDir(const char* programTitle, const char* fileName) 
	{

		headTitle(programTitle);
		readAndFind(fileName);
		cout << "Thank you for using " << programTitle << " directory." << endl;
	}

	

}



