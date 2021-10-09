#ifndef CDATE_H
#define CDATE_H

#include <iostream>

using namespace std;
// Declaration of the Date class.

class CDate {
public:
    CDate(int = 1, int = 1, int = 1900); // constructor
    //CDate();
    ~CDate();
    void print() const; // print date in day/month/year format
    void setDate(int, int, int);
    int checkDay(int a,int b,int c);
    int difDate(CDate d2);
    bool operator== (const CDate& rhs);
    friend ostream& operator<< (ostream& os, CDate &d);
    CDate& operator++();
    CDate& operator++(int);
private:
    int month; // 1-12
    int day; // 1-31 based on month
    int year; // any year
    int checkDay(); //utility function to test day for month/year
}; // end class CDate

#endif // CDATE_H
