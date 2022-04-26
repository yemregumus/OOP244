/* Workshop #5 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-02-17
When I finish P1	: 2022-02-17
When I finish P2	: 2022-02-21 */

/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
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

#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio() {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const {
        return m_value;
    }
    
    Portfolio::operator const char*() const {
        return m_stock;
    }

    Portfolio::operator char() const {
        return m_type;
    }

    Portfolio::operator bool() const {
        
        bool returnValue = false;

        if (m_type == 'G' || m_type == 'V' || m_type == 'I')
        {
            returnValue = true;
        }

        return returnValue;
    }

    bool Portfolio::operator~() const{
        bool returnValue = false;

        if (m_value < 0)
        {
            returnValue = true;
        }

        return returnValue;
    }

    Portfolio& Portfolio::operator+=(double addDoubleValue) {
        if (addDoubleValue >= 0 && *this)
        {
            m_value += addDoubleValue;    
        }

        return *this;
    }

    Portfolio& Portfolio::operator-=(double subDoubleValue) {
        if (subDoubleValue >= 0 && *this)
        {
            m_value -= subDoubleValue;
        }

        return *this;        
    }

    Portfolio& Portfolio::operator<<(Portfolio& RightValue) {

        if (RightValue && *this) {
            if (this != &RightValue) {

                m_value += RightValue.m_value;

                RightValue.emptyPortfolio();
            }
        }

        return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& LeftValue) {
        
        if (LeftValue && *this) {
            if (this != &LeftValue) {

                LeftValue.m_value += m_value;

                this->emptyPortfolio();
            }
        }

        return *this;
    }

    double operator+(const Portfolio& leftValue, const Portfolio& rightValue) {
        
        double returnValue = 0;

        returnValue = double(leftValue) + double(rightValue);

        return returnValue;
    }

    double operator+=(double& leftDoubleValue, const Portfolio& rightValue) {

        leftDoubleValue += double(rightValue);

        return leftDoubleValue;
    }

}