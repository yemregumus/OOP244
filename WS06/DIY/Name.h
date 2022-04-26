/* Workshop #6 Part #2
Full name		        : Yunus Gumus
Student ID number	    : 150331197
Seneca email address	: ygumus@myseneca.ca
Section code		    : NCC
When I Start to WS  	: 2022-03-01
When I finish P1	    : 2022-03-03
When I finish P2	    : 2022-03-05 */


#ifndef SDDS_NAME_H
#define SDDS_NAME_H

#include <iostream>

namespace sdds {

    class Name {
    private:

        char* n_firstName{};
        char* n_middleName{};
        char* n_lastName{};
        bool flagSetShort = false;
        void setEmpty();
        char* allocateAndCopy(const char* name);
        bool validName(const char* name) const;

    public:
        Name();
        Name(const char* firstName);
        Name(const char* firstName,
            const char* lastName);
        Name(const char* firstName,
            const char* middleName,
            const char* lastName);
        Name(const Name& name);

        ~Name();
        void setShort(bool value);
        operator bool() const;
        Name& operator = (const Name& name);
        Name& operator += (const char* str);
        friend std::ostream& operator << (std::ostream& ostr,
            const Name& name);
        friend std::istream& operator >> (std::istream& istr, Name& name);
    };
}
#endif //!SDDS_NAME_H