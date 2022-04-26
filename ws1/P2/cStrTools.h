/* Workshop #1 Part #2
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC              */

#ifndef SDDS_CSTRTOOLS_H 
#define SDDS_CSTRTOOLS_H
namespace sdds {


char toLower(char ch);
int strCmp(const char* s1, const char* s2);
int strnCmp(const char* s1, const char* s2, int len);
void strCpy(char* des, const char* src);
int strLen(const char* str);
const char* strStr(const char* str, const char* find);
int isAlpha(char ch);
int isSpace(char ch);
void trim(char word[]);
void toLowerCaseAndCopy(char des[], const char source[]);

}
#endif