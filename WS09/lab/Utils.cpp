/* Workshop #9 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-28
When I finish P1	: 2022-03-29
When I finish P2	: TBD*/


#define _CRT_SECURE_NO_WARNINGS

#include "Utils.h"
using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    void Utils::alocpy(char*& destination, const char* source, int size) {

        delete[] destination;
        destination = nullptr;
        int length = (int)strlen(source);

        if (source != nullptr)
        {
            if (size)
            {
                if (length < size)
                {
                    destination = new char[++length];
                    strcpy(destination, source);
                }
                else
                {
                    int s = size + 1;
                    destination = new char[s];
                    strncpy(destination, source, size);
                }
            }
            else
            {
                destination = new char[++length];
                strcpy(destination, source);
            }
        }
    }

    int Utils::getint(const char* prompt)
    {
        int foolproof = 0;
        bool flag = true;

        if (prompt)
        {
            cout << endl;
            cout << prompt;
        }
        while (flag) {

            cin >> foolproof;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Invalid Integer, retry: ";
            }
            else
            {
                flag = false;
            }
        }

        return foolproof;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    {
        int intValue = 0;
        bool flag = true;

        while (flag)
        {
            intValue = getint(prompt);

            if (intValue >= min && intValue <= max)
            {
                flag = false;
            }
            else
            {
                if (errMes != nullptr)
                {

                    cout << errMes << ", retry: ";
                }
                else
                {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                }
                prompt = nullptr;
            }

        }

        return intValue;
    }

    const bool Utils::getTestMode() const
    {
        return m_testMode;
    }

    int Utils::getFileLength(std::istream& is) {
        int len{};
        if (is) {
            // save the current read position
            std::streampos cur = is.tellg();
            // go to the end
            is.seekg(0, ios::end);
            // let what is the positions (end position = size)
            len = is.tellg();
            // now go back to where you were.
            is.seekg(cur);
        }
        return len;
    }


}