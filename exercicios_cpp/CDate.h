#ifndef _DATE1_H
#define _DATE1_H
#include <iostream>

using std::ostream;
using std::istream;

#include <iomanip>


using namespace std;

class CDate {
	 
  public:
    CDate(int d = 1, int m = 1, int a = 1900); // constructor
    ~CDate();  
    void print() const;  // print date in day/month/year format
    void setDate(int d, int m, int a);
   	int difDate(CDate d2); 

    CDate& operator+(const int nd);
    CDate& operator++();
	
	bool operator== (const CDate& rhs){ 
		return rhs.day==day && rhs.month==month && rhs.year==year;
	}

  private:
    int month;  // 1-12
    int day;    // 1-31 based on month
    int year;   // any year
    int checkDay(); //utility function to test day for month/year
    friend ostream &operator<< (ostream &,  CDate&);
}; // end class CDate

#endif

