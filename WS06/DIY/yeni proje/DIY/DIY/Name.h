#ifndef SDDS_NAME_H
#define SDDS_NAME_H

#include <iostream>

namespace sdds {
    class Name {
    private:

        char* n_firstName{};
        char* n_middleName{};
        char* n_lastName{};
        bool flagSetShort;
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