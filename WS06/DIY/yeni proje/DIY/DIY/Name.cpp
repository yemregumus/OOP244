#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstring>

#include <string>

#include "Name.h"

using namespace std;
namespace sdds {

    Name::Name() {
        setEmpty();
    }

    Name::Name(const char* firstName) {
        if (validName(firstName)) {
            delete[] n_firstName;
            n_firstName = allocateAndCopy(firstName);
        }
        else {
            setEmpty();
        }
    }

    Name::Name(const char* firstName, const char* lastName) {
        if (validName(firstName) && validName(lastName)) {
            delete[] n_firstName;
            n_firstName = allocateAndCopy(firstName);
            delete[] n_lastName;
            n_lastName = allocateAndCopy(lastName);
        }
        else {
            setEmpty();
        }
    }

    Name::Name(const char* firstName, const char* middleName, const char* lastName) {
        if (validName(firstName) && validName(middleName) && validName(lastName)) {
            delete[] n_firstName;
            n_firstName = allocateAndCopy(firstName);
            delete[] n_middleName;
            n_middleName = allocateAndCopy(middleName);
            delete[] n_lastName;
            n_lastName = allocateAndCopy(lastName);
        }
        else {
            setEmpty();
        }
    }

    Name::Name(const Name& name) {
        if (name) {
            delete[] n_firstName;
            n_firstName = allocateAndCopy(name.n_firstName);

            delete[] n_middleName;

            if (name.n_middleName) {
                n_middleName = allocateAndCopy(name.n_middleName);
            }
            else {
                n_middleName = nullptr;
            }
            delete[] n_lastName;

            if (name.n_lastName) {
                n_lastName = allocateAndCopy(name.n_lastName);
            }
            else {
                n_lastName = nullptr;
            }
        }
        else {
            setEmpty();
        }

    }

    Name::~Name() {
        delete[] n_firstName;
        n_firstName = nullptr;
        delete[] n_middleName;
        n_middleName = nullptr;
        delete[] n_lastName;
        n_lastName = nullptr;
    }

    void Name::setShort(bool value) {

        flagSetShort = value;
    }

    Name::operator bool() const {
        return n_firstName != nullptr;
    }

    Name& Name::operator =(const Name& name) {
        if (this != &name) {
            if (name) {
                delete[] n_firstName;
                n_firstName = allocateAndCopy(name.n_firstName);

                delete[] n_middleName;

                if (name.n_middleName) {
                    n_middleName = allocateAndCopy(name.n_middleName);
                }
                else {
                    n_middleName = nullptr;
                }
                delete[] n_lastName;

                if (name.n_lastName) {
                    n_lastName = allocateAndCopy(name.n_lastName);
                }
                else {
                    n_lastName = nullptr;
                }

            }
            else {
                setEmpty();
            }
        }

        return *this;
    }

    Name& Name::operator += (const char* str) {

        if (validName(str)) {
            if (n_firstName == nullptr) {
                n_firstName = new char[strlen(str) + 1];
                strcpy(n_firstName, str);
            }
            else if (n_middleName == nullptr) {
                n_middleName = new char[strlen(str) + 1];
                strcpy(n_middleName, str);
            }
            else if (n_lastName == nullptr) {
                n_lastName = new char[strlen(str) + 1];
                strcpy(n_lastName, str);
            }
            else {
                setEmpty();
            }
        }
        else {
            setEmpty();
        }

        return *this;
    }

    void Name::setEmpty() {
        delete[] n_firstName;
        n_firstName = nullptr;
        delete[] n_middleName;
        n_middleName = nullptr;
        delete[] n_lastName;
        n_lastName = nullptr;
    }

    char* Name::allocateAndCopy(const char* name) {
        char* np;
        np = new char[strlen(name) + 1];
        strcpy(np, name);

        return np;
    }

    bool Name::validName(const char* name) const {
        bool returnValue = true;
        if (name == nullptr || strlen(name) == 0) {
            returnValue = false;
        }
        else {
            for (int i = 0; i < strlen(name); i++) {
                if (isspace(name[i])) {
                    returnValue = false;
                    break;
                }
            }
        }
        return returnValue;
    }

    std::ostream& operator << (std::ostream& ostr, const Name& name) {

        if (name)
        {
            ostr << name.n_firstName;

            if (name.n_middleName)
            {
                if (name.flagSetShort)
                {
                    ostr << ' ' << name.n_middleName[0] << '.';
                }
                else
                {
                    ostr << ' ' << name.n_middleName;
                }
            }
            if (name.n_lastName)
            {
                ostr << ' ' << name.n_lastName;
            }
           
        }
        else
        {
            ostr << "Bad Name" << endl;
        }
        return ostr;
    }
    std::istream& operator >> (std::istream& istr, Name& name) {
        
        string str;
        string namesArray[4];
        string delimiter = " ";
        size_t pos = 0;
        string token;
        int i = 0;
        bool flagEmptyState = false;


        if(getline(istr, str))
        {
           
            while ((pos = str.find(delimiter)) != string::npos) {
                token = str.substr(0, pos);
                namesArray[i] = token;
                /*cout << "isim = " << token << endl;*/
                str.erase(0, pos + delimiter.length());
                i++;
                if (i == 3)
                {
                    flagEmptyState = true;                   
                    break;
                }
            }
            if (flagEmptyState)
            {
                name.setEmpty();
            }
            else
            {
                namesArray[i] = str;

                if (i == 0)
                {
                    name.n_firstName = name.allocateAndCopy(namesArray[0].c_str());
                }
                else if (i == 1)
                {
                    name.n_firstName = name.allocateAndCopy(namesArray[0].c_str());
                    name.n_lastName = name.allocateAndCopy(namesArray[1].c_str());
                }
                else if (i == 2)
                {
                    name.n_firstName = name.allocateAndCopy(namesArray[0].c_str());
                    name.n_middleName = name.allocateAndCopy(namesArray[1].c_str());
                    name.n_lastName = name.allocateAndCopy(namesArray[2].c_str());

                }
            }          
        }
        return istr;
    }

}