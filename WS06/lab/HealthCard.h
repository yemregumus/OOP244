#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

#include <iostream>

namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
      char* m_name{};
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];

   private:
     
      void setEmpty();
      void allocateAndCopy(const char* name);
      bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;      
      void extractChar(std::istream& istr, char ch) const;
      std::ostream& printIDInfo(std::ostream& ostr)const;
      void set(const char* name, long long number, const char vCode[], const char sNumber[]);
      std::istream& read(std::istream& istr);
   
   public:
       

      HealthCard(const char* = nullptr, long long = 0, const char[] = {}, const char[] = {});
      HealthCard(const HealthCard& hc);
      ~HealthCard();

      operator bool() const;
      std::ostream& print(std::ostream& ostr, bool toFile = true) const;      
      HealthCard& operator=(const HealthCard& hc);
      friend std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
      friend std::istream& operator>>(std::istream& istr, HealthCard& hc);
   };

   
   

}
#endif // !SDDS_HealthCard_H


