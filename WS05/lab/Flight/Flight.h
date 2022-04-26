/* Workshop #5 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-02-17
When I finish P1	: 2022-02-17
When I finish P2	: TBD*/

/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>
#include <cstring>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;

      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char*() const;
      bool operator ~() const;

      Flight& operator =(Flight& source);
      
      Flight& operator =(int posNumPassenger);

      Flight& operator =(double setFuelToThisAmount);

      Flight& operator +=(double addFuelToTank);

      Flight& operator +=(int addPassengers);

      Flight& operator -=(double reduceFuel);

      Flight& operator -=(int takePassengers);

      Flight& operator <<(Flight& rightFlight);

      Flight& operator >>(Flight& leftFlight);

   };

   int operator +(const Flight& leftPlane, const Flight& rightPlane);

   int& operator +=(int& intValue, Flight& rightPlane);
}
#endif // SDDS_FLIGHT_H