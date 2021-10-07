#ifndef CDATE_H
#define CDATE_H

// Declaration of the Date class.

class CDate {
public:
    CDate(int = 1, int = 1, int = 1900); // constructor
    //CDate();
    ~CDate();
    void print() const; // print date in day/month/year format
private:
    int month; // 1-12
    int day; // 1-31 based on month
    int year; // any year
    int checkDay(); //utility function to test day for month/year
}; // end class CDate

#endif // CDATE_H
