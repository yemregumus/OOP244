#ifndef SDDS_TEMPS_H_
#define SDDS_TEMPS_H_
#include <iostream>
#include "Collection.h"

namespace sdds {

	template <typename T>
	Collection<T> select(const T arrayOfData[] , int sizeOfArray, const T& data) {
		
		int counter = 0, j = 0;

		for (int i = 0; i < sizeOfArray; i++){
			if (arrayOfData[i] == data)
			{		
				counter++;
			}
		}
		
		Collection<T> returnCollection(counter);

		for (int i = 0; i < sizeOfArray; i++) {
			if (arrayOfData[i] == data)
			{
				returnCollection[j] = arrayOfData[i];
				j++;
			}
		}

		return returnCollection;
	}
	
	template <typename T>
	void printCollection(const Collection<T>& obj, const char* str) {

		std::cout << str << std::endl;
		
		for (int i = 0; i < obj.size(); i++){

			std::cout << obj[i] << std::endl;
		}
		
	}
}
#endif 
