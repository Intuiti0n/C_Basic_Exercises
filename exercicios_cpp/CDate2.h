#ifndef DATE1_H
#define DATE1_H
#include <iostream>
using std::ostream;

class CDate {
 friend ostream& operator<< (ostream& os, CDate &d);
 public:
    CDate(int = 1, int = 1, int = 1900); // constructor
    ~CDate();  
    void print() const;  // print date in day/month/year format
    void setDate(int, int, int);
    int difDate(CDate d2);
    int convData();
    bool operator== (const CDate& rhs);
    CDate& operator++();    
    CDate& operator++(int);
    CDate& operator+(const int nd);
 private:
    int month;  // 1-12
    int day;    // 1-31 based on month
    int year;   // any year
    int checkDay(); //utility function to test day for month/year
    bool yearBis(int);
}; // end class CDate
#endif
