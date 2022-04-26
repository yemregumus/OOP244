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
Filename: Flight.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const {
        
        bool returnValue = false;

        if (m_passengers > 0)
        {
            if (m_fuel >= (m_passengers * 600))
            {
                returnValue = true;
            }
        }
        
        return returnValue;
    }

    Flight::operator int() const {

        return m_passengers;
    }

    Flight::operator double() const {
        return m_fuel;
    }

    Flight::operator const char* () const {


        return m_title;
    }

    bool Flight::operator ~() const {

        bool returnValue = false;

        if (m_passengers == 0)
        {
            returnValue = true;
        }

        return returnValue;
    }

    Flight& Flight::operator =(Flight &source){
        
        m_passengers = source.m_passengers;
        m_fuel = source.m_fuel;
        strcpy(m_title, source.m_title);

        source.emptyPlane();

        return *this;
    }

    Flight& Flight::operator =(int posNumPassenger) {

        if (posNumPassenger >= 0 && posNumPassenger <= Boen747Capacity)
        {
            m_passengers = posNumPassenger;
        }

        return *this;
    }

    Flight& Flight::operator =(double setFuelToThisAmount) {

        if (setFuelToThisAmount >= 0.0 && setFuelToThisAmount <= FuelTankCapacity)
        {
            m_fuel = setFuelToThisAmount;
        }

        return *this;
    }

    Flight& Flight::operator +=(double addFuelToTank) {

        if (addFuelToTank >= 0 && m_fuel < FuelTankCapacity)
        {
            m_fuel += addFuelToTank;
            if (m_fuel > FuelTankCapacity)
            {
                m_fuel = FuelTankCapacity;
            }
        }

        return *this;
    }

    Flight& Flight::operator +=(int addPassengers) {

        if (addPassengers >= 0 && m_passengers < Boen747Capacity)
        {
            m_passengers += addPassengers;
            if (m_passengers > Boen747Capacity)
            {
                m_passengers = Boen747Capacity;
            }
        }

        return *this;
    }
    
    Flight& Flight::operator -=(double reduceFuel) {

        if (reduceFuel >= 0)
        {
            m_fuel -= reduceFuel;
            if (m_fuel < 0)
            {
                m_fuel = 0;
            }
        }

        return *this;
    }

    Flight& Flight::operator -=(int takePassengers) {

        if (takePassengers >= 0)
        {
            m_passengers -= takePassengers;
            if (m_passengers < 0)
            {
                m_passengers = 0;
            }
        }

        return *this;
    }

    Flight& Flight::operator <<(Flight& rightFlight) {

        int difference = 0;


        if (rightFlight && *this) {
            if (this != &rightFlight) {
                      
                m_passengers += rightFlight.m_passengers;
            
                difference = m_passengers - Boen747Capacity;
            
                rightFlight.m_passengers = difference;

                if (rightFlight.m_passengers < 0) {
                    rightFlight.m_passengers = 0;
                }
                if (m_passengers > Boen747Capacity) {
                    m_passengers = Boen747Capacity;
                }
            }
        }

        return *this;
    }

    Flight& Flight::operator >>(Flight& leftFlight) {

        int difference = 0;

        if (leftFlight && *this) {
            if (this != &leftFlight) {

                leftFlight.m_passengers += m_passengers;

                difference = leftFlight.m_passengers - Boen747Capacity;

                m_passengers = difference;

                if (m_passengers < 0) {
                    m_passengers = 0;
                }
                if (leftFlight.m_passengers > Boen747Capacity) {
                    leftFlight.m_passengers = Boen747Capacity;
                }
            }
        }

        return *this;

    }

    int operator +(const Flight& leftPlane, const Flight& rightPlane) {

        int returnValue = 0;

        returnValue = int(leftPlane) + int(rightPlane);

        return returnValue;

    }


    int& operator +=(int& intValue, Flight& rightPlane) {

        intValue += int(rightPlane);

        return intValue;
    }


}