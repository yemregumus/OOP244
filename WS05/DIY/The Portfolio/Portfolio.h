/* Workshop #5 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-02-17
When I finish P1	: 2022-02-17
When I finish P2	: 2022-02-21*/

/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <cstring>
#include <string>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;
      void emptyPortfolio();
   public:
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       void dispPortfolio() const;
       std::ostream& display()const;

       operator double() const;
       operator const char* () const;
       operator char() const;
       operator bool() const;
       bool operator ~() const;

       Portfolio& operator +=(double addDoubleValue);
       Portfolio& operator -=(double subDoubleValue);
       Portfolio& operator <<(Portfolio& RightValue);
       Portfolio& operator >>(Portfolio& LeftValue);

   };

   double operator +(const Portfolio& leftValue, const Portfolio& rightValue);
   double operator +=(double& leftDoubleValue, const Portfolio& rightValue);

}
#endif // SDDS_Portfolio_H_